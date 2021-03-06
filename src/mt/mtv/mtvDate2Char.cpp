/** 
 *  Copyright (c) 1999~2017, Altibase Corp. and/or its affiliates. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License, version 3,
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 

/***********************************************************************
 * $Id: mtvDate2Char.cpp 47933 2011-06-30 02:01:37Z et16 $
 **********************************************************************/

#include <mte.h>
#include <mtc.h>
#include <mtf.h>
#include <mtk.h>
#include <mtv.h>
#include <mtl.h>

#include <mtdTypes.h>
#include <mtuProperty.h>

extern mtvModule mtvDate2Char;

extern mtdModule mtdChar;
extern mtdModule mtdDate;

extern mtxModule mtxFromDateTo; /* PROJ-2632 */

static IDE_RC mtvEstimate( mtcNode*     aNode,
                           mtcTemplate* aTemplate,
                           mtcStack*    aStack,
                           SInt         aRemain,
                           mtcCallBack* aCallBack );

IDE_RC mtvCalculate_Date2Char( mtcNode*     aNode,
                               mtcStack*    aStack,
                               SInt         aRemain,
                               void*        aInfo,
                               mtcTemplate* aTemplate );

mtvModule mtvDate2Char = {
    &mtdChar,
    &mtdDate,
    MTV_COST_DEFAULT | MTV_COST_LOSS_PENALTY | MTV_COST_GROUP_PENALTY,
    mtvEstimate
};

static const mtcExecute mtvExecute = {
    mtf::calculateNA,
    mtf::calculateNA,
    mtf::calculateNA,
    mtf::calculateNA,
    mtvCalculate_Date2Char,
    NULL,
    mtx::calculateNA,
    mtk::estimateRangeNA,
    mtk::extractRangeNA
};

static IDE_RC mtvEstimate( mtcNode*     aNode,
                           mtcTemplate* aTemplate,
                           mtcStack*    aStack,
                           SInt,
                           mtcCallBack* )
{
    aStack[0].column = aTemplate->rows[aNode->table].columns+aNode->column;

    aTemplate->rows[aNode->table].execute[aNode->column] = mtvExecute;

    /* PROJ-2632 */
    aTemplate->rows[aNode->table].execute[aNode->column].mSerialExecute
        = mtxFromDateTo.mGetExecute( mtdChar.id, mtdChar.id );

    IDE_TEST( mtc::initializeColumn( aStack[0].column,
                                     & mtdChar,
                                     1,
                                     MTC_TO_CHAR_MAX_PRECISION,
                                     0 )
              != IDE_SUCCESS );

    return IDE_SUCCESS;

    IDE_EXCEPTION_END;

    return IDE_FAILURE;
}

IDE_RC mtvCalculate_Date2Char( mtcNode*,
                               mtcStack*    aStack,
                               SInt,
                               void*,
                               mtcTemplate* aTemplate )
{
    mtdDateType* sDate;
    mtdCharType* sChar;
    UInt         sLength;
    SInt         sFormatLen;

    IDE_ASSERT( aTemplate != NULL );
    IDE_ASSERT( aTemplate->dateFormat != NULL );

    if( mtdDate.isNull( aStack[1].column,
                        aStack[1].value ) == ID_TRUE )
    {
        mtdChar.null( aStack[0].column,
                      aStack[0].value );
    }
    else
    {
        sDate = (mtdDateType*)aStack[1].value;
        sChar = (mtdCharType*)aStack[0].value;
        sLength = 0;
        sFormatLen = idlOS::strlen( aTemplate->dateFormat );

        IDE_TEST( mtdDateInterface::toChar( sDate,
                                            sChar->value,
                                            &sLength,
                                            aStack[0].column->precision,
                                            (UChar*)aTemplate->dateFormat,
                                            sFormatLen )
                  != IDE_SUCCESS );

        // PROJ-1436
        // dateFormat을 참조했음을 표시한다.
        aTemplate->dateFormatRef = ID_TRUE;

        sChar->length = (UShort)sLength;
    }

    return IDE_SUCCESS;

    IDE_EXCEPTION_END;

    return IDE_FAILURE;
}
