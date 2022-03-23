/**
 * \file
 *   Functional test of basic EVS Send Event APIs
 *
 *   Demonstration of how to register and use the UT assert functions.
 */

/*
 * Includes
 */

#include "cfe_test.h"

void TestSendEvent(void)
{
    UtPrintf("Testing: CFE_EVS_SendEvent");

    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_INFORMATION, "OK Send"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_INFORMATION, NULL), CFE_EVS_INVALID_PARAMETER);

    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_DEBUG, "OK (Debug) Send"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_DEBUG, NULL), CFE_EVS_INVALID_PARAMETER);

    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_ERROR, "OK (Error) Send"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_ERROR, NULL), CFE_EVS_INVALID_PARAMETER);

    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_CRITICAL, "OK (Critical) Send"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendEvent(0, CFE_EVS_EventType_CRITICAL, NULL), CFE_EVS_INVALID_PARAMETER);
}

void TestSendEventAppID(void)
{
    CFE_ES_AppId_t AppId;

    UtPrintf("Testing: CFE_EVS_SendEventWithAppID");

    CFE_ES_GetAppID(&AppId);

    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_INFORMATION, AppId, "OK App ID"), CFE_SUCCESS);

    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_INFORMATION, AppId, NULL),
                      CFE_EVS_INVALID_PARAMETER);
    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_INFORMATION, CFE_ES_APPID_UNDEFINED, "OK"),
                      CFE_EVS_APP_ILLEGAL_APP_ID);

    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_DEBUG, AppId, " OK (Debug) App ID"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_DEBUG, AppId, NULL), CFE_EVS_INVALID_PARAMETER);
    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_DEBUG, CFE_ES_APPID_UNDEFINED, "OK (Debug)"),
                      CFE_EVS_APP_ILLEGAL_APP_ID);

    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_ERROR, AppId, "OK (Error) App ID"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_ERROR, AppId, NULL), CFE_EVS_INVALID_PARAMETER);
    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_ERROR, CFE_ES_APPID_UNDEFINED, "OK (Error)"),
                      CFE_EVS_APP_ILLEGAL_APP_ID);

    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_CRITICAL, AppId, "OK (Critical) App ID"),
                      CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_CRITICAL, AppId, NULL),
                      CFE_EVS_INVALID_PARAMETER);
    UtAssert_INT32_EQ(
        CFE_EVS_SendEventWithAppID(0, CFE_EVS_EventType_CRITICAL, CFE_ES_APPID_UNDEFINED, "OK (Critical)"),
        CFE_EVS_APP_ILLEGAL_APP_ID);
}

void TestSendTimedEvent(void)
{
    CFE_TIME_SysTime_t Time = {1000, 1000};
    UtPrintf("Testing: CFE_EVS_SendTimedEvent");

    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_INFORMATION, "OK Time"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_INFORMATION, NULL), CFE_EVS_INVALID_PARAMETER);

    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_DEBUG, "Ok (Debug) Time"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_DEBUG, NULL), CFE_EVS_INVALID_PARAMETER);

    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_ERROR, "Ok (Error) Time"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_ERROR, NULL), CFE_EVS_INVALID_PARAMETER);

    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_CRITICAL, "Ok (Critical) Time"), CFE_SUCCESS);
    UtAssert_INT32_EQ(CFE_EVS_SendTimedEvent(Time, 0, CFE_EVS_EventType_CRITICAL, NULL), CFE_EVS_INVALID_PARAMETER);
}

void EVSSendTestSetup(void)
{
    UtTest_Add(TestSendEvent, NULL, NULL, "Test Send Event");
    UtTest_Add(TestSendEventAppID, NULL, NULL, "Test Send Event with App ID");
    UtTest_Add(TestSendTimedEvent, NULL, NULL, "Test Send Timed Event");
}
