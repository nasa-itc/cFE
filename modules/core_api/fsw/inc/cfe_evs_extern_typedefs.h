/**
 * @file
 *
 * Declarations and prototypes for cfe_evs_extern_typedefs module
 */

#ifndef CFE_EVS_EXTERN_TYPEDEFS_H
#define CFE_EVS_EXTERN_TYPEDEFS_H

/* This header may be generated from an EDS file,
 * tools are available and the feature is enabled */
#ifdef CFE_EDS_ENABLED_BUILD

/* Use the EDS generated version of these types */
#include "cfe_evs_eds_typedefs.h"

#else
/* Use the local definitions of these types */

#include "common_types.h"

/**
 * @brief Label definitions associated with CFE_EVS_MsgFormat_Enum_t
 */
enum CFE_EVS_MsgFormat
{

    /**
     * @brief Short Format Messages
     */
    CFE_EVS_MsgFormat_SHORT = 0,

    /**
     * @brief Long Format Messages
     */
    CFE_EVS_MsgFormat_LONG = 1
};

/**
 * @brief Identifies format of log messages
 *
 * @sa enum CFE_EVS_MsgFormat
 */
typedef uint8 CFE_EVS_MsgFormat_Enum_t;

/**
 * @brief Label definitions associated with CFE_EVS_LogMode_Enum_t
 */
enum CFE_EVS_LogMode
{

    /**
     * @brief Overwrite Log Mode
     */
    CFE_EVS_LogMode_OVERWRITE = 0,

    /**
     * @brief Discard Log Mode
     */
    CFE_EVS_LogMode_DISCARD = 1
};

/**
 * @brief Identifies handling of log messages after storage is filled
 *
 * @sa enum CFE_EVS_LogMode
 */
typedef uint8 CFE_EVS_LogMode_Enum_t;

/**
 * @brief Label definitions associated with CFE_EVS_EventType_Enum_t
 */
enum CFE_EVS_EventType
{

    /**
     * @brief Events that are intended only for debugging, not nominal operations
     */
    CFE_EVS_EventType_DEBUG = 1,

    /**
     * @brief Events that identify a state change or action that is not an error
     */
    CFE_EVS_EventType_INFORMATION = 2,

    /**
     * @brief Events that identify an error but are not catastrophic (e.g. - bad command
     */
    CFE_EVS_EventType_ERROR = 3,

    /**
     * @brief Events that identify errors that are unrecoverable autonomously
     */
    CFE_EVS_EventType_CRITICAL = 4
};

/**
 * @brief Identifies type of event message
 *
 * @sa enum CFE_EVS_EventType
 */
typedef uint16 CFE_EVS_EventType_Enum_t;

/**
 * @brief Label definitions associated with CFE_EVS_EventFilter_Enum_t
 */
enum CFE_EVS_EventFilter
{

    /**
     * @brief Binary event filter
     */
    CFE_EVS_EventFilter_BINARY = 0
};

/**
 * @brief Identifies event filter schemes
 *
 * @sa enum CFE_EVS_EventFilter
 */
typedef uint8 CFE_EVS_EventFilter_Enum_t;

/**
 * @brief Label definitions associated with CFE_EVS_EventOutput_Enum_t
 */
enum CFE_EVS_EventOutput
{

    /**
     * @brief Output Port 1
     */
    CFE_EVS_EventOutput_PORT1 = 1,

    /**
     * @brief Output Port 2
     */
    CFE_EVS_EventOutput_PORT2 = 2,

    /**
     * @brief Output Port 3
     */
    CFE_EVS_EventOutput_PORT3 = 3,

    /**
     * @brief Output Port 4
     */
    CFE_EVS_EventOutput_PORT4 = 4
};

/**
 * @brief Identifies event output port
 *
 * @sa enum CFE_EVS_EventOutput
 */
typedef uint8 CFE_EVS_EventOutput_Enum_t;

#endif /* CFE_EDS_ENABLED_BUILD */

#endif /* CFE_EVS_EXTERN_TYPEDEFS_H */
