/**
 * @file
 *   This file implements the error code functions used by OpenThread core modules.
 */

#include <mpp/error.hpp>
#include <mpp/macro_utils.h>


namespace mpp {
  
  
  
const char *ErrorToString( Error aError )
{
  static const char *const kErrorStrings[kNumErrors] = {
    "OK",               //  0 - kErrorNone
    "Failed",           //  1 - kErrorFailed
    "NoBufs",           //  2 - kErrorNoBufs
    "Drop",             //  3 - kErrorDrop
    "Busy",             //  4 - kErrorBusy
    "Parse",            //  5 - kErrorParse
    "InvalidArgs",      //  6 - kErrorInvalidArgs
    "Abort",            //  7 - kErrorAbort
    "NotImplemented",   //  8 - kErrorNotImplemented
    "InvalidState",     //  9 - kErrorInvalidState
    "NotFound",         // 10 - kErrorNotFound 
    "Already",          // 11 - kErrorAlredy
    "NotCapable",       // 12 - kErrorNotCapable
    "ResponseTimeout",  // 13 - kErrorResponseTimeout
    "DisabledFeature",  // 14 - kErrorDisabledFeature
    "InvalidCommand",   // 15 - kErrorInvalidCommand
  };    
    
  return aError < MPP_ARRAY_LENGTH(kErrorStrings) ? kErrorStrings[aError] : "UnknownErrorType";
}
  
  
  
  
} // namespace mpp
