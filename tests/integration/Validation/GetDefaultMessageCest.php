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

namespace Phalcon\Test\Integration\Validation;

use IntegrationTester;

/**
 * Class GetDefaultMessageCest
 */
class GetDefaultMessageCest
{
    /**
     * Tests Phalcon\Validation :: getDefaultMessage()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-16
     */
    public function validationGetDefaultMessage(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getDefaultMessage()');

        $I->skipTest('Need implementation');
    }
}
