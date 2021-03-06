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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class WithRequestTargetCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withRequestTarget()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithRequestTarget(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withRequestTarget()');
        $request     = new ServerRequest();
        $newInstance = $request->withRequestTarget('/test');

        $I->assertNotEquals($request, $newInstance);

        $expected = '/';
        $actual   = $request->getRequestTarget();
        $I->assertEquals($expected, $actual);

        $expected = '/test';
        $actual   = $newInstance->getRequestTarget();
        $I->assertEquals($expected, $actual);
    }
}
