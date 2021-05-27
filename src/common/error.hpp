#pragma once


/**
 * @file
 *   This file defines the errors used by mpp-core.
 */



#include "mpp/config/core_config.h"
#include <mpp/error.h>
#include <stdint.h>


namespace mpp {
  
/**
 * This type represents error codes used by OpenThread core modules.
 *
 */
typedef mppError Error;



/*
 * The `MPP_ERROR_*` enumeration values are re-defined using `kError` style format.
 * See `mpp/error.h` for more details about each error.
 *
 */


constexpr Error kErrorNone            = MPP_ERROR_NONE;
constexpr Error kErrorFailed          = MPP_ERROR_FAILED;
constexpr Error kErrorNoBufs          = MPP_ERROR_NO_BUFS;
constexpr Error kErrorDrop            = MPP_ERROR_DROP;
constexpr Error kErrorBusy            = MPP_ERROR_BUSY;
constexpr Error kErrorParse           = MPP_ERROR_PARSE;
constexpr Error kErrorInvalidArgs     = MPP_ERROR_INVALID_ARGS;
constexpr Error kErrorAbort           = MPP_ERROR_ABORT;
constexpr Error kErrorNotImplemented  = MPP_ERROR_NOT_IMPLEMENTED;
constexpr Error kErrorInvalidState    = MPP_ERROR_INVALID_STATE;
constexpr Error kErrorNotFound        = MPP_ERROR_NOT_FOUND;
constexpr Error kErrorAlredy          = MPP_ERROR_ALREADY;
constexpr Error kErrorNotCapable      = MPP_ERROR_NOT_CAPABLE;
constexpr Error kErrorResponseTimeout = MPP_ERROR_RESPONSE_TIMEOUT;
constexpr Error kErrorDisabledFeature = MPP_ERROR_DISABLED_FEATURE;
constexpr Error kErrorInvalidCommand  = MPP_ERROR_INVALID_COMMAND;
constexpr Error kErrorGeneric         = MPP_ERROR_GENERIC;

constexpr uint8_t kNumErrors = MPP_NUM_ERRORS;







/**
 * This function converts an `Error` into a string.
 *
 * @param[in]  aError     An error.
 *
 * @returns  A string representation of @p aError.
 *
 */
const char *ErrorToString(Error aError);


  
} // namespace mpp


