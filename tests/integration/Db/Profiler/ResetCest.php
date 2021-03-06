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

namespace Phalcon\Test\Integration\Db\Profiler;

use IntegrationTester;
use Phalcon\Events\Manager;
use Phalcon\Test\Fixtures\Db\ProfilerListener;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class ResetCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
    }


    /**
     * Tests Phalcon\Db\Profiler :: reset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbProfilerReset(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler - reset()');
        $I->skipTest('Need implementation');
    }


    public function testDbMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
    }

    private function executeTests(IntegrationTester $I, $connection)
    {
        $eventsManager = new Manager();
        $listener      = new ProfilerListener();

        $eventsManager->attach('db', $listener);

        $connection->setEventsManager($eventsManager);

        $profiler = $listener->getProfiler();

        $connection->query('SELECT * FROM personas LIMIT 3');
        $connection->query('SELECT * FROM personas LIMIT 100');
        $connection->query('SELECT * FROM personas LIMIT 5');
        $connection->query('SELECT * FROM personas LIMIT 10');
        $connection->query('SELECT * FROM personas LIMIT 15');

        $I->assertCount(
            5,
            $profiler->getProfiles()
        );

        $I->assertEquals(
            5,
            $profiler->getNumberTotalStatements()
        );

        $I->assertInternalType(
            'double',
            $profiler->getTotalElapsedSeconds()
        );

        $I->assertEquals(
            0,
            $profiler->getPoints()
        );

        $profiler->reset();

        $I->assertCount(
            0,
            $profiler->getProfiles()
        );

        $I->assertEquals(
            0,
            $profiler->getNumberTotalStatements()
        );
    }

    public function testDbPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
    }

    public function testDbSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $connection = $this->getService('db');

        $this->executeTests($I, $connection);
    }
}
