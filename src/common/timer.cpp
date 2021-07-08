#include "mpp/timer.hpp"
#include "mpp/platform/toolchain.h"

using namespace mpp;

void TimerScheduler::ProcessTimers(  )
{
  Timer *timer = mTimerList.GetHead();

  if (timer)
  {
    Time now( mTimeBase() );

    if (now >= timer->mFireTime)
    {
      Remove(*timer, aAlarmApi);
      timer->Handler();
      ExitNow();
    }
  }

exit:
  return;
}




void Add( Timer& aTimer )
{
  Timer *prev = nullptr;
  Time now( mTimeBase() );

  Remove(aTimer, aAlarmApi);

  for ( Timer *cur = mTimerList.GetHead();  cur;  prev = cur, cur = cur->GetNext() )
  {
    if (aTimer.DoesFireBefore(*cur, now))
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




