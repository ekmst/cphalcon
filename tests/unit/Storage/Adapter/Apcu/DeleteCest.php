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

namespace Phalcon\Test\Unit\Storage\Adapter\Apcu;

use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

class DeleteCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: delete()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterApcuDelete(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - delete()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key = 'cache-data';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertTrue($actual);

        $actual = $adapter->has($key);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: delete() - twice
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterApcuDeleteTwice(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - delete() - twice');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key = 'cache-data';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: delete() - unknown
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterApcuDeleteUnknown(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - delete() - unknown');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key    = 'cache-data';
        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
    }
}
