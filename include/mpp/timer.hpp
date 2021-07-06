#pragma once

#include <cstdint>
#include "mixin.hpp"
#include "linked_list.hpp"


namespace mpp {
  
using Time = uint32_t;    
class Timer;

    


class TimerScheduler: public NonCopyable< TimerScheduler >
{
  friend class Timer;
  
public:
  typedef Time (&TimeBase)();    
  
  
  TimerScheduler( TimeBase aTimeBase )
       : mTimeBase(aTimeBase)
  {    
  }
  
  /**
   * This method allow change TimeBase.
   *
   */
  void SetTimeBase( TimeBase aTimeBase );

  /**
   * This method processes the running timers.
   *
   */
  void ProcessTimers();
  
private:
    
  /**
   * This method adds a timer instance to the timer scheduler.
   *
   * @param[in]  aTimer     A reference to the timer instance.
   *
   */
  void Add(Timer& aTimer);
  
  
  /**
   * This method removes a timer instance to the timer scheduler.
   *
   * @param[in]  aTimer     A reference to the timer instance.
   *
   */
  void Remove(Timer& aTimer);  
    
  
private:
  LinkedList<Timer> mTimerList;
  TimeBase mTimeBase;
};












class Timer : public InstanceLocator, public LinkedListEntry<Timer>
{
  friend class TimerScheduler;
  friend class LinkedListEntry<Timer>;
    
public:
  /**
   * This type defines a function reference which is invoked when the timer expires.
   *
   * @param[in]  aTimer    A reference to the expired timer instance.
   *
   */
  typedef void (&Handler)(Timer &aTimer);    
  
  /**
   * This constructor creates a timer instance.
   *
   * @param[in]  aTimeScheduler   A reference to the TimeScheduler instance.
   * @param[in]  aHandler         A pointer to a function that is called when the timer expires.
   *
   */
  Timer(TimerScheduler &aTimeScheduler, Handler aHandler)
        : mTimeScheduler(aTimeScheduler)
        , mHandler(aHandler)
        , mInterval()
        , mStartTime()
        , mNext(this)
    {
    }
    
  
  /**
   * This method schedules the timer to fire after a given delay (in tick) from now.
   * @param[in]  aTick The delay in tick
   *
   */
  void Start( Time aDelay );
  
  
  /**
   * This method schedules the timer to fire after a given delay (in tick) from a given start time.
   *
   * @param[in]  aStartTime  The start time.
   * @param[in]  aDelay      The delay in milliseconds. It must not be longer than `kMaxDelay`.
   *
   */
  void StartAt(Time aStartTime, uint32_t aDelay);
    
    
  /**
   * This method reload the timer with setted interval. If interval equal 0, 
   * the timer will not be reloaded.
   */
  void Reload();
  
  
  /**
   * This method stops the timer.
   *
   */
  void Stop();
 
  
  
  /**
   * This method returns the elapsed time of the timer.
   *
   * @returns The elapsed time.
   *
   */
  Time GetElapsedTime();
  
  
  
  /**
   * This method returns setted the time interval
   *
   * @returns The interval.
   *
   */
  Time GetInterval() const { return mInterval; }

    
  /**
   * This method indicates whether or not the timer instance is running.
   *
   * @retval TRUE   If the timer is running.
   * @retval FALSE  If the timer is not running.
   *
   */
  bool IsRunning() const { return (mNext != this); }
  
  
  
  /**
   * This static method returns the current time in tick.
   *
   * @returns The current time in tick.
   *
   */
  Time GetNow() { return mTimeScheduler->mTimeBase(); }
    
    

protected:
  /**
   * This method indicates if the fire time of this timer is strictly before the fire time of a second given timer.
   *
   * @param[in]  aSecondTimer   A reference to the second timer object.
   * @param[in]  aNow           The current time (milliseconds or microsecond, depending on timer type).
   *
   * @retval TRUE  If the fire time of this timer object is strictly before aTimer's fire time
   * @retval FALSE If the fire time of this timer object is the same or after aTimer's fire time.
   *
   */
  bool DoesFireBefore(const Timer &aSecondTimer, Time aNow) const;

  void TimeOut() { mHandler(*this); }

  TimeScheduler *mTimeScheduler;
  Time mInterval;
  Time mStartTime;
  Handler  mHandler;
  Timer   *mNext;
};

  



}  // namespace mpp



