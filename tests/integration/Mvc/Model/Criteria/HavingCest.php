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

namespace Phalcon\Test\Integration\Mvc\Model\Criteria;

use IntegrationTester;

/**
 * Class HavingCest
 */
class HavingCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: having()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaHaving(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - having()');
        $I->skipTest('Need implementation');
    }
}
