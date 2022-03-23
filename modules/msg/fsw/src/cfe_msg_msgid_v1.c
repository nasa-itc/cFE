/******************************************************************************
 *  Message id access functions, cFS version 1 implementation
 */
#include "cfe_msg.h"
#include "cfe_msg_priv.h"
#include "cfe_error.h"
#include "cfe_platform_cfg.h"
#include "cfe_sb.h"

/*----------------------------------------------------------------
 *
 * Function: CFE_MSG_GetMsgId
 *
 * Implemented per public API
 * See description in header file for argument/return detail
 *
 *-----------------------------------------------------------------*/
CFE_Status_t CFE_MSG_GetMsgId(const CFE_MSG_Message_t *MsgPtr, CFE_SB_MsgId_t *MsgId)
{

    CFE_SB_MsgId_Atom_t msgidval;

    if (MsgPtr == NULL || MsgId == NULL)
    {
        return CFE_MSG_BAD_ARGUMENT;
    }

    msgidval = (MsgPtr->CCSDS.Pri.StreamId[0] << 8) + MsgPtr->CCSDS.Pri.StreamId[1];
    *MsgId   = CFE_SB_ValueToMsgId(msgidval);

    return CFE_SUCCESS;
}

/*----------------------------------------------------------------
 *
 * Function: CFE_MSG_SetMsgId
 *
 * Implemented per public API
 * See description in header file for argument/return detail
 *
 *-----------------------------------------------------------------*/
CFE_Status_t CFE_MSG_SetMsgId(CFE_MSG_Message_t *MsgPtr, CFE_SB_MsgId_t MsgId)
{

    CFE_SB_MsgId_Atom_t msgidval = CFE_SB_MsgIdToValue(MsgId);

    if (MsgPtr == NULL || msgidval > CFE_PLATFORM_SB_HIGHEST_VALID_MSGID)
    {
        return CFE_MSG_BAD_ARGUMENT;
    }

    /* Shift and mask bytes to be endian agnostic */
    MsgPtr->CCSDS.Pri.StreamId[0] = (msgidval >> 8) & 0xFF;
    MsgPtr->CCSDS.Pri.StreamId[1] = msgidval & 0xFF;

    return CFE_SUCCESS;
}
