/**
 * @file
 *   This file includes logging related macro/function definitions.
 */

#pragma once

#include <mpp/config/core_config.h>
#include <mpp/platform/logging.h>
#include <mpp/error.h>

namespace mpp {

/**
 * This type represents the log level.
 */
enum class LogLevel: int
{ 
  None, Crit, Warn, Note, Info, Debg 
};


LogLevel LogGetLevel();
mppError    LogSetLevel( LogLevel aLogLevel );


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
  void LogCrit( const char *aRegion, const char *aFormat, ... );
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
  void LogWarn( const char *aRegion, const char *aFormat, ... );
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
  void LogNote( const char *aRegion, const char *aFormat, ... );
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
  void LogInfo( const char *aRegion, const char *aFormat, ... );
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
#if OPENTHREAD_CONFIG_LOG_LEVEL < OT_LOG_LEVEL_DEBG
  #define otLogDebg(aRegion, aRegionPrefix, ...)
#else
  void LogDebg( const char *aRegion, const char *aFormat, ... );
#endif



} // namespace mpp
