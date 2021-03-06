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
 
package com.altibase.altilinker.adlp.op;

import java.nio.BufferUnderflowException;
import java.nio.ByteBuffer;

import com.altibase.altilinker.adlp.*;
import com.altibase.altilinker.adlp.type.*;

public class ExecuteRemoteStatementResultOp extends ResultOperation
{
    public long  mRemoteStatementId   = 0;
    public short mRemoteNodeSessionId = 0;
    public int   mStatementType       = StatementType.Unknown;
    public int   mExecuteResult       = 0;
    
    public ExecuteRemoteStatementResultOp()
    {
        super(OpId.ExecuteRemoteStatementResult, true);
    }
    
    protected boolean writeOperation(CommonHeader aCommonHeader,
                                     ByteBuffer   aOpPayload)
    {
        fillCommonHeader(aCommonHeader);
        
        try
        {
            if (canWriteData() == true)
            {
                // write data
                writeLong (aOpPayload, mRemoteStatementId);
                writeShort(aOpPayload, mRemoteNodeSessionId);
                writeInt  (aOpPayload, mStatementType);
                writeInt  (aOpPayload, mExecuteResult);
            }
        }
        catch (BufferUnderflowException e)
        {
            return false;
        }

        return true;
    }
}
