#include <iostream>
#include <chrono>
#include <mpp/logging.h>
#include <mpp/timer.hpp>

static const char* sPrefix = "[MAIN]";


#ifdef __cplusplus
extern "C" {
#endif


uint32_t GetSystemTickMs();

#ifdef __cplusplus
}
#endif



void TimerHandler( mpp::Timer &aTimer ) {
  aTimer.Start(1000);
  mppLogInfo( sPrefix, "%s", "ALARM!!!");

  std::cout << aTimer.GetNow() << std::endl;

  return;
}



int main()
{
  static mpp::TimerScheduler mTimeScheduler(GetSystemTickMs);
  static mpp::Timer mTimer( mTimeScheduler, TimerHandler );
  mTimer.Start(1000);

  while(1) {
    mTimeScheduler.ProcessTimers();
  }

  return 0; 
}
