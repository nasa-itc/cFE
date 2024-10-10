/************************************************************************
 * NASA Docket No. GSC-18,719-1, and identified as “core Flight System: Bootes”
 *
 * Copyright (c) 2020 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

#include "cfe_msg.h"
#include "cfe_msg_priv.h"
#include "cfe_msg_defaults.h"
#include "cfe_time.h"

/*----------------------------------------------------------------
 *
 * Implemented per public API
 * See description in header file for argument/return detail
 *
 *-----------------------------------------------------------------*/
CFE_Status_t CFE_MSG_Verify(const CFE_MSG_Message_t *MsgPtr, bool *VerifyStatus)
{
    if (MsgPtr == NULL || VerifyStatus == NULL)
    {
        return CFE_MSG_BAD_ARGUMENT;
    }

    /*
     * In the default implementation, there is not anything to check here.
     * Only commands have a checksum, but the value of that checksum was historically
     * not enforced by CFE.
     *
     * This is mainly a hook for user expansion, in case a custom implementation
     * has message verification capability.
     */
    *VerifyStatus = true;

    return CFE_SUCCESS;
}