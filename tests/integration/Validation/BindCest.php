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
use Phalcon\Validation;
use stdClass;

/**
 * Class BindCest
 */
class BindCest
{
    /**
     * Tests Phalcon\Validation :: bind()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function validationBind(IntegrationTester $I)
    {
        $I->wantToTest('Validation - bind()');

        $user = new stdClass();

        $data = [
            'name' => 'Sid',
            'city' => 'Busan',
        ];

        $validation = new Validation();

        $validation->bind($user, $data);

        $I->assertSame(
            $user,
            $validation->getEntity()
        );

        $I->assertSame(
            $data,
            $validation->getData()
        );
    }
}
