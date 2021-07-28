#include <mpp/platform/toolchain.h>
#include <mpp/logging.h>
#include <mpp/string.hpp>

#if MPP_CONFIGLOG_LEVEL_DYNAMIC_ENABLE
  static mppLogLevel log_level = static_cast<LogLevel>(MPP_CONFIG_LOG_LEVEL);
#endif


static void Log( mppLogLevel aLevel,
                 const char *aLevelPrefix,
                 const char *aRegionPrefix,
                 const char *aFormat,
                 va_list aArgs )
{
  mpp::String<MPP_CONFIG_LOG_MAX_SIZE> logString;
  mpp::StringWriter writer(logString);

  #if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    VerifyOrExit( LogGetLevel() >= aLogLevel );
  #endif // MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE

  #if MPP_CONFIG_LOG_PREPEND_LEVEL
    writer.Append("%s", aLevelPrefix);
  #endif // MPP_CONFIG_LOG_PREPEND_LEVEL

  writer.Append("%s", aRegionPrefix);
  writer.AppendVarArgs(aFormat, aArgs);
  mppPlatLog( aLevel, logString.AsCString() );

#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
exit:
  return;
#endif // MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
}




#ifdef __cplusplus
extern "C" {
#endif

mppLogLevel mppLogGetLevel()
{
#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    return log_level;
#else
    return static_cast<mppLogLevel>(MPP_CONFIG_LOG_LEVEL);
#endif
}


#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
mppError LoggingSetLevel( LogLevel aLogLevel )
{
  mppError error = MPP_ERROR_NONE;

  if ( static_cast<int>(aLogLevel) <= MPP_LOG_LEVEL_DEBG &&
       static_cast<int>(aLogLevel) >= MPP_LOG_LEVEL_NONE )
  {
    log_level = aLogLevel;   
  }
  else
  {
    error = MPP_ERROR_INVALID_ARGS;
  }

  return error;
}
#endif



#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_CRIT
void mppLogCrit(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelCrit = "[CRIT]";
  va_list args;

  va_start(args, aFormat);
  Log(MPP_LOG_LEVEL_CRIT, sLogLevelCrit, aRegion, aFormat, args);
  va_end(args);
}
#endif




#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_WARN
void mppLogWarn(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelWarn = "[WARN]";
  va_list args;

  va_start(args, aFormat);
  Log(MPP_LOG_LEVEL_WARN, sLogLevelWarn, aRegion, aFormat, args);
  va_end(args);
}
#endif





#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_NOTE
void mppLogNote(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelNote = "[NOTE]";
  va_list args;

  va_start(args, aFormat);
  Log(MPP_LOG_LEVEL_NOTE, sLogLevelNote, aRegion, aFormat, args);
  va_end(args);
}
#endif




#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_INFO
void mppLogInfo(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelInfo = "[INFO]";
  va_list args;

  va_start(args, aFormat);
  Log(MPP_LOG_LEVEL_NOTE, sLogLevelInfo, aRegion, aFormat, args);
  va_end(args);
}
#endif





#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_DEBG
void mppLogDebg(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelDebg = "[DEBG]";
  va_list args;

  va_start(args, aFormat);
  Log(MPP_LOG_LEVEL_DEBG, sLogLevelDebg, aRegion, aFormat, args);
  va_end(args);
}
#endif




MPP_TOOL_WEAK void mppPlatLog( mppLogLevel aLevel, const char *aLogLine )
{
  MPP_UNUSED_VARIABLE(aLogLine);
}



#ifdef __cplusplus
}
#endif











  
