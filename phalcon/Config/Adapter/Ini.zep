
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Adapter;

use Phalcon\Config;
use Phalcon\Config\Exception;

/**
 * Phalcon\Config\Adapter\Ini
 *
 * Reads ini files and converts them to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 * [database]
 * adapter = Mysql
 * host = localhost
 * username = scott
 * password = cheetah
 * dbname = test_db
 *
 * [phalcon]
 * controllersDir = "../app/controllers/"
 * modelsDir = "../app/models/"
 * viewsDir = "../app/views/"
 * </code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new \Phalcon\Config\Adapter\Ini("path/config.ini");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *</code>
 *
 * PHP constants may also be parsed in the ini file, so if you define a constant
 * as an ini value before calling the constructor, the constant's value will be
 * integrated into the results. To use it this way you must specify the optional
 * second parameter as INI_SCANNER_NORMAL when calling the constructor:
 *
 * <code>
 * $config = new \Phalcon\Config\Adapter\Ini(
 *     "path/config-with-constants.ini",
 *     INI_SCANNER_NORMAL
 * );
 * </code>
 */
class Ini extends Config
{
    /**
     * Phalcon\Config\Adapter\Ini constructor
     */
    public function __construct(string! filePath, mode = null) -> void
    {
        var iniConfig, section, sections, directives, path, lastValue;
        array config;

        // Default to INI_SCANNER_RAW if not specified
        if null === mode {
            let mode = INI_SCANNER_RAW;
        }

        let iniConfig = parse_ini_file(filePath, true, mode);

        if unlikely iniConfig === false {
            throw new Exception(
                "Configuration file " . basename(filePath) . " can't be loaded"
            );
        }

        let config = [];

        for section, directives in iniConfig {
            if typeof directives == "array" {
                let sections = [];

                for path, lastValue in directives {
                    let sections[] = this->parseIniString(
                        (string) path,
                        lastValue
                    );
                }

                if count(sections) {
                    let config[section] = call_user_func_array(
                        "array_replace_recursive",
                        sections
                    );
                }
            } else {
                let config[section] = this->cast(directives);
            }
        }

        parent::__construct(config);
    }

    /**
     * We have to cast values manually because parse_ini_file() has a poor
     * implementation.
     *
     * @param mixed ini The array casted by `parse_ini_file`
     */
    protected function cast(var ini) -> bool | null | double | int | string
    {
        var key, val;

        if typeof ini == "array" {
            for key, val in ini {
                let ini[key] = this->cast(val);
            }

            return ini;
        }

        // Decode true
        if ini === "true" || ini === "yes" || strtolower(ini) === "on" {
            return true;
        }

        // Decode false
        if ini === "false" || ini === "no" || strtolower(ini) === "off" {
            return false;
        }

        // Decode null
        if ini === "null" {
            return null;
        }

        // Decode float/int
        if typeof ini == "string" && is_numeric(ini) {
            if preg_match("/[.]+/", ini) {
                return (double) ini;
            } else {
                return (int) ini;
            }
        }

        return ini;
    }
    
    /**
     * Build multidimensional array from string
     *
     * <code>
     * $this->parseIniString("path.hello.world", "value for last key");
     *
     * // result
     * [
     *      "path" => [
     *          "hello" => [
     *              "world" => "value for last key",
     *          ],
     *      ],
     * ];
     * </code>
     */
    protected function parseIniString(string! path, var value) -> array
    {
        var pos, key;

        let value = this->cast(value);
        let pos = strpos(path, ".");

        if pos === false {
            return [
                path: value
            ];
        }

        let key = substr(path, 0, pos);
        let path = substr(path, pos + 1);

        return [
            key: this->parseIniString(path, value)
        ];
    }
}
