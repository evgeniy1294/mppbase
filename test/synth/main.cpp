#include <iostream>
#include <chrono>
#include <array>
#include <unistd.h>
#include <mpp/logging.h>
#include <mpp/timer.hpp>
#include <mpp/error.hpp>
#include <mpp/crc_logic.hpp>
#include <mpp/utils.hpp>
#include <mpp/rtc_time.hpp>
#include <mpp/systick.hpp>
#include <mpp/storage.hpp>

static const char* sPrefix = "[MAIN]";


#ifdef __cplusplus
extern "C" {
#endif


uint32_t GetSystemTickMs();

#ifdef __cplusplus
}
#endif


void TimerHandler( mpp::Timer &aTimer, void* aUserArg ) {
  aTimer.Start(1000);
  mppLogInfo( sPrefix, "%s", "FIRST!!!");

  return;
}


void TimerSecondHandler( mpp::Timer &aTimer, void* aUserArg) {
  aTimer.Start(100);
  mppLogInfo( sPrefix, "%s", "SECOND!!!");

  return;
}


static std::array<std::uint8_t, 10> array;


int main()
{
  static mpp::TimerScheduler mTimeScheduler(GetSystemTickMs);
  static mpp::Timer mTimer( mTimeScheduler, TimerHandler );
  static mpp::Timer mTimerSecond( mTimeScheduler, TimerSecondHandler );
  mTimer.Start(1000);
  mTimerSecond.Start(100);

  while(1) {
    mTimeScheduler.ProcessTimers();
    usleep(100);
  }


  //std::cout << mpp::IsFussyEqual(1.32f, 1.35f, 0.04f) << std::endl;
  //std::cout << mpp::IsFussyNull(-0.01f, 0.001) << std::endl;

  return 0; 
}
