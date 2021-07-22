#include <mpp/platform/toolchain.h>
#include <mpp/logging.hpp>
#include <mpp/string.hpp>


#if MPP_CONFIGLOG_LEVEL_DYNAMIC_ENABLE
namespace mpp {
  static LogLevel log_level = static_cast<LogLevel>(MPP_CONFIG_LOG_LEVEL); 
}
#endif


using namespace mpp;

LogLevel LogGetLevel()
{
#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
    return log_level;
#else
    return static_cast<LogLevel>(MPP_CONFIG_LOG_LEVEL);
#endif
}





#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
Error LoggingSetLevel( LogLevel aLogLevel )
{
  Error error = kErrorNone;

  if ( static_cast<int>(aLogLevel) <= MPP_LOG_LEVEL_DEBG &&
       static_cast<int>(aLogLevel) >= MPP_LOG_LEVEL_NONE )
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





static void Log( LogLevel  aLevel,
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
  
  #if OPENTHREAD_CONFIG_LOG_PREPEND_LEVEL
    writer.Append("%s", aLevelPrefix);
  #endif // OPENTHREAD_CONFIG_LOG_PREPEND_LEVEL
  
  writer.Append("%s", aRegionPrefix);
  writer.AppendVarArgs(aFormat, aArgs);
  mppPlatLog( logString.AsCString() );

#if MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
exit:
  return;
#endif // MPP_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE
}





#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_CRIT
void LogCrit(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelCrit = "[CRIT]";
  va_list args;

  va_start(args, aFormat);
  Log(LogLevel::Crit, sLogLevelCrit, aRegion, aFormat, args);
  va_end(args);
}
#endif




#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_WARN
void LogWarn(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelWarn = "[WARN]";
  va_list args;

  va_start(args, aFormat);
  Log(LogLevel::Warn, sLogLevelWarn, aRegion, aFormat, args);
  va_end(args);
}
#endif





#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_NOTE
void LogNote(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelNote = "[NOTE]";
  va_list args;

  va_start(args, aFormat);
  Log(LogLevel::Note, sLogLevelNote, aRegion, aFormat, args);
  va_end(args);
}
#endif




#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_INFO
void LogInfo(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelInfo = "[INFO]";
  va_list args;

  va_start(args, aFormat);
  Log(LogLevel::Info, sLogLevelInfo, aRegion, aFormat, args);
  va_end(args);
}
#endif





#if MPP_CONFIG_LOG_LEVEL >= MPP_LOG_LEVEL_DEBG
void LogDebg(const char *aRegion, const char *aFormat, ...)
{
  static const char* sLogLevelDebg = "[DEBG]";
  va_list args;

  va_start(args, aFormat);
  Log(LogLevel::Debg, sLogLevelDebg, aRegion, aFormat, args);
  va_end(args);
}
#endif
  
  


MPP_TOOL_WEAK void mppPlatLog( const char *aLogLine )
{
  MPP_UNUSED_VARIABLE(aLogLine);
}



  
