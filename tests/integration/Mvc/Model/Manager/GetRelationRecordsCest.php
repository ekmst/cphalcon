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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;

/**
 * Class GetRelationRecordsCest
 */
class GetRelationRecordsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: getRelationRecords()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelManagerGetRelationRecords(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - getRelationRecords()');
        $I->skipTest('Need implementation');
    }
}
