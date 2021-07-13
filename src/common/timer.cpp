#include "mpp/timer.hpp"
#include "mpp/platform/toolchain.h"

using namespace mpp;


void TimerScheduler::ProcessTimers(  )
{
  Timer *timer = mTimerList.GetHead();

  if (timer)
  {
    Time now( mTimeSource() );

    if (now - timer->mStartTime) >= timer->mInterval) 
    {
      Remove( *timer );
      timer->Alarm();

      if ( timer->mRepeat )
      {
        timer->mStartTime = now;
        Add( Timer& aTimer )
      }
    }
  }

  return;
}




void Add( Timer& aTimer )
{
  Timer *prev = nullptr;
  Time now( mTimeSource() );

  Remove( aTimer );

  for ( Timer* cur = mTimerList.GetHead();  cur;  prev = cur, cur = cur->GetNext() )
  {
    if (aTimer.DoesAlarmBefore(*cur, now))
    {
      break;
    }
  }

  if (prev == nullptr)
  {
    mTimerList.Push(aTimer);
  }
  else
  {
     mTimerList.PushAfter(aTimer, *prev);
  }
}




void TimerScheduler::Remove( Timer& aTimer )
{
  mfVerifyOrExit(aTimer.IsRunning());

  if (mTimerList.GetHead() == &aTimer)
  {
    mTimerList.Pop();
  }
  else
  {
    mfIgnoreError(mTimerList.Remove(aTimer));
  }

  aTimer.SetNext(&aTimer);

exit:
  return;
}




void Timer::Start( Time aInterval, bool aRepeat = false )
{
  mStartTime = mTimerScheduler->Now();
  mInterval  = aInterval;
  mRepeat    = aRepeat;
  
  mTimerScheduler->Add( *this );
}



void Timer::Start()
{
  mfVerifyOrExit( mInterval != 0 );
  Start( mInterval );
  
exit:
  return;
}



void Timer::Stop()
{
  mTimerScheduler->Remove( *this );
}



Time Timer::GetRemainTime()
{
  Time now( mTimerScheduler->Now() );
  Time remain = (mStartTime + mInterval) - now;
  
  return ( remain > mInterval ) ? 0 : remain;
}



bool Timer::DoesAlarmBefore( const Timer &aSecondTimer ) const
{
  return this->GetRemainTime() < aSecondTimer.GetRemainTime();
}




