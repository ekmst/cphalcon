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

namespace Phalcon\Test\Unit\Firewall\Adapter\Annotations;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Annotations;
use UnitTester;

class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Annotations ::
     * getEventsManager()/setEventsManager()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - getEventsManager()/setEventsManager()');

        $firewall      = new Annotations(new Memory());
        $eventsManager = new Manager();

        $firewall->setEventsManager($eventsManager);

        $actual = $firewall->getEventsManager();
        $I->assertEquals($eventsManager, $actual);
    }
}
