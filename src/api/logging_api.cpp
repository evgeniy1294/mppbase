/**
 * @file
 *   This file implements the mpp logging related APIs.
 */



#include "mpp/config/core_config.h"
#include <mpp/logging.h>



#if MPP_CONFIGLOG_LEVEL_DYNAMIC_ENABLE

namespace mpp {
  static mppLogLevel log_level = MPP_CONFIG_LOG_LEVEL; 
}

#endif



mppLogLevel mppLoggingGetLevel()
{
#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    return mpp::log_level;
#else
    return static_cast<mppLogLevel>(MPP_CONFIG_LOG_LEVEL);
#endif
}



#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
mppError mppLoggingSetLevel(mppLogLevel aLogLevel)
{
  mppError error = kErrorNone;

  if (aLogLevel <= MPP_LOG_LEVEL_DEBG && aLogLevel >= MPP_LOG_LEVEL_NONE)
  {
    log_level = aLogLevel;   
  }
  else
  {
    error = kErrorInvalidArgs;
  }

  return error;
}
#endif



