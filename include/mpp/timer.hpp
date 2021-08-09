#pragma once

#include <cstdint>
#include <mpp/mixin.hpp>
#include <mpp/linked_list.hpp>


namespace mpp {
  
using Time = uint32_t;    
class Timer;

    


class TimerScheduler: public NonCopyable< TimerScheduler >
{
  friend class Timer;
  
public:
  typedef Time (TimeSource)();    
  
  
  TimerScheduler( TimeSource aTimeSource )
       : mTimeSource(aTimeSource)
  {    
  }
  
  /**
   * This method allow change TimeSource.
   *
   */
  void SetTimeSource( TimeSource aTimeSource ) { mTimeSource = aTimeSource; }

  /**
   * This method processes the running timers.
   *
   */
  void ProcessTimers();
  
  Time Now() { return mTimeSource(); }
  
private:
    
  /**
   * This method adds a timer instance to the timer scheduler.
   *
   * @param[in]  aTimer     A reference to the timer instance.
   *
   */
  void Add( Timer& aTimer );
  
  
  /**
   * This method removes a timer instance to the timer scheduler.
   *
   * @param[in]  aTimer     A reference to the timer instance.
   *
   */
  void Remove( Timer& aTimer );  
    
  
private:
  LinkedList<Timer> mTimerList;
  TimeSource* mTimeSource;
};











// Add Timer type { OneShot or Periodic }
class Timer: public LinkedListEntry<Timer>
{
  friend class TimerScheduler;
  friend class LinkedListEntry<Timer>;
    
public:
  /**
   * This type defines a function reference which is invoked when the timer expires.
   *
   * @param[in]  aTimer  A reference to the expired timer instance.
   * @param[in]  aArg    A pointer to user arg
   *
   */
  typedef void (Callback)(Timer &aTimer, void* aUserArg);
  
  /**
   * This constructor creates a timer instance.
   *
   * @param[in]  aTimeScheduler   A reference to the TimeScheduler instance.
   * @param[in]  aHandler         A pointer to a function that is called when the timer expires.
   * @param[in]  aUserArg         A pointer to user arg
   *
   */
  Timer(TimerScheduler &aTimeScheduler, Callback aCallback, void* aUserArg = nullptr )
        : mTimerScheduler(&aTimeScheduler)
        , mCallback(aCallback)
        , mInterval()
        , mStartTime()
        , mNext(this)
        , mUserArg(aUserArg)
  {
  }
    
  
  /**
   * This method schedules the timer to fire after a given delay (in tick) from now.
   * @param[in]  aInterval The delay in tick
   */
  void Start( Time aInterval );
  
  
    
    
  /**
   * This method reload the timer with setted interval. If interval equal 0, 
   * the timer will not be reloaded.
   */
  void Start();
  
  
  /**
   * This method stops the timer.
   *
   */
  void Stop();
 
  
  
  /**
   * This method returns the remain time of the timer.
   *
   * @returns The remain time.
   *
   */
  Time GetRemainTime();
  
  
  
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
  Time GetNow() { return mTimerScheduler->Now(); }
    
    

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
  bool DoesAlarmBefore( Timer &aSecondTimer ) /* const */;

  void Alarm() { mCallback(*this, mUserArg); }

  TimerScheduler *mTimerScheduler;
  Time mInterval;
  Time mStartTime;
  Callback* mCallback;
  Timer *mNext;
  void* mUserArg;
};

  



}  // namespace mpp



