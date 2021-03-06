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

namespace Phalcon\Test\Unit\Logger\Adapter\Syslog;

use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

class ProcessCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: process()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterSyslogProcess(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - process()');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

        $item = new Item(
            'Message 1',
            'debug',
            Logger::DEBUG
        );

        $adapter->process($item);

        $I->assertTrue(
            $adapter->close()
        );
    }
}
