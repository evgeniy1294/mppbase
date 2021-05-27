#pragma once


#include <mpp/error.h>
#include <mpp/platform/logging.h>



#ifdef __cplusplus
extern "C" {
#endif
  
  

/**
 * @addtogroup api-logging
 *
 * @brief
 *   This module includes OpenThread logging related definitions.
 *
 * @{
 *
 */




/**
 * This function returns the current log level.
 *
 * If dynamic log level feature `OPENTHREAD_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE` is enabled, this function returns the
 * currently set dynamic log level. Otherwise, this function returns the build-time configured log level.
 *
 * @returns The log level.
 *
 */
mppLogLevel mppLoggingGetLevel(void);

/**
 * This function sets the log level.
 *
 * @note This function requires `OPENTHREAD_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE=1`.
 *
 * @param[in]  aLogLevel               The log level.
 *
 * @retval OT_ERROR_NONE            Successfully updated log level.
 * @retval OT_ERROR_INVALID_ARGS    Log level value is invalid.
 *
 */
mppError mppLoggingSetLevel(otLogLevel aLogLevel);




  
  
  
/**
 * @}
 *
 */


  
  
#ifdef __cplusplus
} // extern "C"
#endif





