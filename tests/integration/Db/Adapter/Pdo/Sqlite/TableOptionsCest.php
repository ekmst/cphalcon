<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;

/**
 * Class TableOptionsCest
 */
class TableOptionsCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: tableOptions()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteTableOptions(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - tableOptions()');
        $I->skipTest('Need implementation');
    }
}
