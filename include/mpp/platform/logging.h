#pragma once


/**
 * @file
 * @brief
 *   This file includes the platform abstraction for the debug log service.
 */


#include <stdarg.h>
#include <stdint.h>



#ifdef __cplusplus
extern "C" {
#endif
  
  
 /**
 * @addtogroup plat-logging
 *
 * @brief
 *   This module includes the platform abstraction for the debug log service.
 *
 * @{
 *
 */

 
 
/**
 * Log level None.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 *
 */
#define MPP_LOG_LEVEL_NONE 0



/**
 * Log level Critical.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 *
 */
#define MPP_LOG_LEVEL_CRIT 1



/**
 * Log level Warning.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 *
 */
#define MPP_LOG_LEVEL_WARN 2



/**
 * Log level Notice.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 *
 */
#define MPP_LOG_LEVEL_NOTE 3



/**
 * Log level Informational.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 *
 */
#define MPP_LOG_LEVEL_INFO 4



/**
 * Log level Debug.
 *
 * @note Log Levels are defines so that embedded implementations can eliminate code at compile time via
 * #if/#else/#endif.
 *
 */
#define MPP_LOG_LEVEL_DEBG 5




/**
 * This type represents the log level.
 *
 */
typedef int mppLogLevel;

 
/**
 * This type represents the log region.
 *
 */
typedef int mppLogRegion
  
  
  
  
/**
 * This function outputs logs.
 *
 * @note Taked from OpenThread
 * @param[in]  aLogLevel   The log level.
 * @param[in]  aLogRegion  The log region.
 * @param[in]  aFormat     A pointer to the format string.
 * @param[in]  ...         Arguments for the format specification.
 *
 */
void mppPlatLog(mppLogLevel aLogLevel, mppLogRegion aLogRegion, const char *aFormat, ...);






/**
 * This (optional) platform function outputs a prepared log line.
 *
 * This platform function is used by OpenThread core when `OPENTHREAD_CONFIG_LOG_DEFINE_AS_MACRO_ONLY` is not enabled
 * (in this case, the OT core itself will prepare a full log line).
 *
 * Note that this function is optional and if not provided by platform layer, a default (weak) implementation is
 * provided and used by OpenThread core as `otPlatLog(aLogLevel, aLogResion, "%s", aLogLine)`.
 *
 * @note Taked from OpenThread
 * @param[in]  aLogLevel   The log level.
 * @param[in]  aLogRegion  The log region.
 * @param[in]  aLogLine    A pointer to a log line string.
 *
 */
void mppPlatLogLine(mppLogLevel aLogLevel, mppLogRegion aLogRegion, const char *aLogLine);



  
  
/**
 * @}
 *
 */

#ifdef __cplusplus
} // extern "C"
#endif

