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

namespace Phalcon\Test\Unit\Firewall\Adapter\Micro\Acl;

use UnitTester;

class IsRouteNameConfigurationCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Micro\Acl :: isRouteNameConfiguration()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterMicroAclIsRouteNameConfiguration(UnitTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Micro\Acl - isRouteNameConfiguration()');

        $I->skipTest('Need implementation');
    }
}
