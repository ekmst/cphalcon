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

namespace Phalcon\Test\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

class GetFilterCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Inline :: getFilter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getFilter()');
        $content = 'p {color: #000099}';
        $asset   = new Css($content);

        $expected = true;
        $this->assetGetFilter($I, $asset, $expected);
    }
}
