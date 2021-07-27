#include <iostream>
#include <chrono>
#include <array>
#include <unistd.h>
#include <mpp/logging.h>
#include <mpp/timer.hpp>
#include <mpp/ring_buffer.hpp>
#include <mpp/error.hpp>
#include <mpp/crc_logic.hpp>

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
  mppLogInfo( sPrefix, "%s", "FIRST!!!");

  return;
}


void TimerSecondHandler( mpp::Timer &aTimer ) {
  aTimer.Start(100);
  mppLogInfo( sPrefix, "%s", "SECOND!!!");

  return;
}


static std::array<std::uint8_t, 10> array;


int main()
{
/*
  static mpp::TimerScheduler mTimeScheduler(GetSystemTickMs);
  static mpp::Timer mTimer( mTimeScheduler, TimerHandler );
  static mpp::Timer mTimerSecond( mTimeScheduler, TimerSecondHandler );
  mTimer.Start(1000);
  mTimerSecond.Start(100);

  while(1) {
    mTimeScheduler.ProcessTimers();
    usleep(100);
  }
*/

  mpp::RingBuffer<decltype(array)::value_type> mRing( array.data(), array.size() );
  mRing.Push(0);
  mRing.Push(1);
  mRing.Push(2);
  mRing.Push(3);
  mRing.Push(4);
  mRing.Push(5);
  mRing.Push(6);
  mRing.Push(7);
  mRing.Push(8);
  mRing.Push(9);

  if ( mRing.TryPush(10) != mpp::kErrorNone ) {
    std::cout << "Push failed, buffer is full" << std::endl;
  }

  mRing.Push(0x0A);
  std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;

  auto tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  if ( mRing.TryPush(11) != mpp::kErrorNone ) {
    std::cout << "Push failed, buffer is full" << std::endl;
  }
  else
  {
    std::cout << "Push success" << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }

  tmp = mRing.Pop();
  if (tmp)
  {
    std::cout << (std::uint32_t)tmp.value() << " ";
    std::cout << "Buffer size is: " << (std::uint32_t)mRing.Size() << std::endl;
  }


  return 0; 
}
