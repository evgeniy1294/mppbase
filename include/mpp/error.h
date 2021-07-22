#pragma once


#ifdef __cplusplus
extern "C" {
#endif

    
/**
 * @addtogroup api-error
 *
 * @brief
 *   This module includes error definitions used in mpp.
 *
 * @{
 *
 */


/**
 * This enumeration represents error codes used throughout mpp.
 *
 */ 
typedef enum mppError 
{
  MPP_ERROR_NONE,                  ///< No error.
  MPP_ERROR_FAILED,                ///< Operation failed.
  MPP_ERROR_NO_BUFS,               ///< Insufficient buffers.
  MPP_ERROR_DROP,                  ///< Packet was dropped.
  MPP_ERROR_BUSY,                  ///< Service is busy and could not service the operation.
  MPP_ERROR_PARSE,                 ///< Failed to parse message.
  MPP_ERROR_INVALID_ARGS,          ///< Input arguments are invalid.
  MPP_ERROR_ABORT,                 ///< Operation was aborted.
  MPP_ERROR_NOT_IMPLEMENTED,       ///< Function or method is not implemented.
  MPP_ERROR_INVALID_STATE,         ///< Cannot complete due to invalid state.
  MPP_ERROR_NOT_FOUND,             ///< The requested item could not be found.
  MPP_ERROR_ALREADY,               ///< The operation is already in progress.
  MPP_ERROR_NOT_CAPABLE,           ///< Operation prevented by mode flags.
  MPP_ERROR_RESPONSE_TIMEOUT,      ///< Response from remote device not received.
  MPP_ERROR_DISABLED_FEATURE,      ///< A feature/functionality disabled by build-time configuration options.
  MPP_ERROR_INVALID_COMMAND,       ///< Input (CLI) command is invalid.
  MPP_NUM_ERRORS,                  ///< The number of defined errors.
  MPP_ERROR_GENERIC = 255,         ///< Generic error (should not use).
} mppError;



/**
 * This function converts an mppError enum into a string.
 *
 * @param[in]  aError     An mppError enum.
 *
 * @returns  A string representation of an mppError.
 *
 */
const char *mppErrorToString(mppError aError);


/**
 * This function ignores an error explicitly.
 *
 * This is primarily used to indicate the intention of developer that
 * the error can be safely ignored or there is guaranteed to be no error.
 *
 * @note: Taked from OpenThread project
 * 
 * @param[in]  aError  The error to be ignored.
 *
 */
static inline void IgnoreError(mppError aError)
{
  MPP_UNUSED_VARIABLE(aError);
}

/**
 * @}
 *
 */


#ifdef __cplusplus
} // extern "C"
#endif




 
