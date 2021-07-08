#pragma once


/**
 * @file
 *   This file defines the errors used by mpp-core.
 */



#include <cstdint>
#include "config/core_config.h"


namespace mpp {
 
/*
 * This enumeration represents error codes used throughout mpp.
 *
 */
enum class Error {
  None,
  Failed,
  NoBufs,
  Drop,
  Busy,
  Parse,
  InvalidArgs,
  Abort,
  NotImplemented,
  InvalidState,
  NotFound,
  Already,
  NotCapable,
  ResponseTimeout,
  DisabledFeature,
  InvalidCommand,
  Generic,

  NumErrors
};


/**
 * This function converts an `Error` into a string.
 *
 * @param[in]  aError     An error.
 *
 * @returns  A string representation of @p aError.
 *
 */
const char *ErrorToString(Error aError);


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
static inline void IgnoreError(otError aError)
{
    OT_UNUSED_VARIABLE(aError);
}


} // namespace mpp


