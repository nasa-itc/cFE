/*
** Includes
*/
#include <string.h>
#include "cfe_tbl.h"

#include "utstubs.h"

/*
** Functions
*/

/*------------------------------------------------------------
 *
 * Default handler for CFE_TBL_Register coverage stub function
 *
 *------------------------------------------------------------*/
void UT_DefaultHandler_CFE_TBL_Register(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    CFE_TBL_Handle_t *TblHandlePtr = UT_Hook_GetArgValueByName(Context, "TblHandlePtr", CFE_TBL_Handle_t *);

    int32 status;

    UT_Stub_GetInt32StatusCode(Context, &status);
    if (status >= 0)
    {
        UT_Stub_CopyToLocal(UT_KEY(CFE_TBL_Register), TblHandlePtr, sizeof(CFE_TBL_Handle_t));
    }
}

/*------------------------------------------------------------
 *
 * Default handler for CFE_TBL_GetAddress coverage stub function
 *
 *------------------------------------------------------------*/
void UT_DefaultHandler_CFE_TBL_GetAddress(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    void **TblPtr = UT_Hook_GetArgValueByName(Context, "TblPtr", void **);

    int32 status;

    UT_Stub_GetInt32StatusCode(Context, &status);
    if (status >= 0 /* JPHFIX: && !UT_Stub_CheckDefaultReturnValue(UT_KEY(CFE_TBL_GetAddress), &ForceValue) */)
    {
        UT_Stub_CopyToLocal(UT_KEY(CFE_TBL_GetAddress), (uint8 *)TblPtr, sizeof(void *));
    }
}

/*------------------------------------------------------------
 *
 * Default handler for CFE_TBL_GetInfo coverage stub function
 *
 *------------------------------------------------------------*/
void UT_DefaultHandler_CFE_TBL_GetInfo(void *UserObj, UT_EntryKey_t FuncKey, const UT_StubContext_t *Context)
{
    CFE_TBL_Info_t *TblInfoPtr = UT_Hook_GetArgValueByName(Context, "TblInfoPtr", CFE_TBL_Info_t *);

    int32 status;

    UT_Stub_GetInt32StatusCode(Context, &status);
    if (status >= 0 &&
        UT_Stub_CopyToLocal(UT_KEY(CFE_TBL_GetInfo), TblInfoPtr, sizeof(*TblInfoPtr)) < sizeof(*TblInfoPtr))
    {
        /* just clear the output struct */
        memset(TblInfoPtr, 0, sizeof(*TblInfoPtr));
    }
}
