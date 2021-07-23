/**
 * @file
 *   This file includes logging related macro/function definitions.
 */

#pragma once

#include <mpp/config/core_config.h>
#include <mpp/platform/logging.h>
#include <mpp/error.h>


#define MPP_LOG_LEVEL_NONE           0
#define MPP_LOG_LEVEL_CRIT           1
#define MPP_LOG_LEVEL_WARN           2
#define MPP_LOG_LEVEL_NOTE           3
#define MPP_LOG_LEVEL_INFO           4
#define MPP_LOG_LEVEL_DEBG           5

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @def LogCrit
 *
 * Logging at log level critical.
 *
 * @param[in]  aRegion   The log region.
 * @param[in]  ...       Arguments for the format specification.
 *
 */
#if MPP_CONFIG_LOG_LEVEL < MPP_LOG_LEVEL_CRIT
  #define LogCrit(aRegion, aRegionPrefix, ...)
#else
  void mppLogCrit( const char *aRegion, const char *aFormat, ... );
#endif


/**
 * @def LogWarn
 *
 * Logging at log level warning.
 *
 * @param[in]  aRegion   The log region.
 * @param[in]  ...       Arguments for the format specification.
 *
 */
#if MPP_CONFIG_LOG_LEVEL < MPP_LOG_LEVEL_WARN
  #define LogWarn(aRegion, aRegionPrefix, ...)
#else
  void mppLogWarn( const char *aRegion, const char *aFormat, ... );
#endif


/**
 * @def LogNote
 *
 * Logging at log level note
 *
 * @param[in]  aRegion   The log region.
 * @param[in]  ...       Arguments for the format specification.
 *
 */
#if MPP_CONFIG_LOG_LEVEL < MPP_LOG_LEVEL_NOTE
  #define LogNote(aRegion, aRegionPrefix, ...)
#else
  void mppLogNote( const char *aRegion, const char *aFormat, ... );
#endif


/**
 * @def LogInfo
 *
 * Logging at log level info.
 *
 * @param[in]  aRegion   The log region.
 * @param[in]  ...       Arguments for the format specification.
 *
 */
#if MPP_CONFIG_LOG_LEVEL < MPP_LOG_LEVEL_INFO
  #define LogInfo(aRegion, aRegionPrefix, ...)
#else
  void mppLogInfo( const char *aRegion, const char *aFormat, ... );
#endif


/**
 * @def LogDebg
 *
 * Logging at log level debug.
 *
 * @param[in]  aRegion   The log region.
 * @param[in]  ...       Arguments for the format specification.
 *
 */
#if MPP_CONFIG_LOG_LEVEL < MPP_LOG_LEVEL_DEBG
  #define LogDebg(aRegion, aRegionPrefix, ...)
#else
  void mppLogDebg( const char *aRegion, const char *aFormat, ... );
#endif





mppLogLevel mppLogGetLevel();
mppError    mppLogSetLevel( mppLogLevel aLogLevel );

#ifdef __cplusplus
}
#endif
