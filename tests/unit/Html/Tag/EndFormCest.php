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

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use const PHP_EOL;
use UnitTester;

class EndFormCest
{
    /**
     * Tests Phalcon\Html\Tag :: endForm()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagEndForm(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - endForm()');

        $tag = new Tag();

        $I->assertEquals(
            '</form>',
            $tag->endForm(false)
        );
    }

    /**
     * Tests Phalcon\Html\Tag :: endForm() - EOL
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagEndFormEol(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - endForm() - EOL');

        $tag = new Tag();

        $I->assertEquals(
            '</form>' . PHP_EOL,
            $tag->endForm()
        );
    }
}
