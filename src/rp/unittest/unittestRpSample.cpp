/** 
 *  Copyright (c) 1999~2017, Altibase Corp. and/or its affiliates. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License, version 3,
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <idl.h>
#include <act.h>

/*
 * Function to demonstrate UnitTest framework
 */
SInt unittestRpGetOne()
{
    return 1;
}

/*
 * ACT_CHECK and ACT_CHECK_DESC demonstration function
 */
void unittestRpTestCheck()
{
    SInt sRet;

    ACT_CHECK( unittestRpGetOne() == 1 );

    sRet = unittestRpGetOne();
    ACT_CHECK_DESC( sRet == 1, ( "unittestRpGetOne() should return 1 but %d", sRet ) );
}

/*
 * ACT_ERROR demonstration function
 */
void unittestRpTestError()
{
    if ( unittestRpGetOne() == 1 )
    {
        ACT_CHECK( unittestRpGetOne() == 1 );
    }
    else
    {
        ACT_ERROR( ( "Error: unittestRpGetOne() should return 1 but %d", unittestRpGetOne() ) );
    }
}

/*
 * ACT_ASSERT and ACT_ASSERT_DESC demonstration function
 */
void unittestRpTestAssert()
{
    SInt sRet;

    ACT_ASSERT( unittestRpGetOne() == 1 );

    sRet = unittestRpGetOne();
    ACT_ASSERT_DESC( sRet == 1, ( "unittestRpGetOne() should return 1 but %d", sRet ) );
}

/*
 * ACT_DUMP and ACT_DUMP_DESC demonstration function
 */
void unittestRpTestDump()
{
    UChar sBuf[] = { 'A', 'B', 'C', 'D', 'E',
                     'A', 'B', 'C', 'D', 'E',
                     'A', 'B', 'C', 'D', 'E',
                     'A', 'B', 'C', 'D', 'E',
                     'A', 'B', 'C', 'D', 'E',
                     'A', 'B', 'C', 'D', 'E',
    };

    if ( unittestRpGetOne() != 1 )
    {
        ACT_DUMP( &sBuf, sizeof( sBuf ) );

        ACT_DUMP_DESC( &sBuf, sizeof( sBuf ), ( "Dump description." ) );
    }
}

int main()
{
    ACT_TEST_BEGIN();

    /* Run function to check ACT_CHECK ACT_CHECK_DESC use */
    unittestRpTestCheck();

    /* Run function to check ACT_ERROR use */
    unittestRpTestError();

    /* Run function to check ACT_ASSERT ACT_ASSERT_DESC use */
    unittestRpTestAssert();

    /* Run function to check ACT_DUMP ACT_DUMP_DESC use */
    unittestRpTestDump();

    ACT_TEST_END();

    return 0;
}
