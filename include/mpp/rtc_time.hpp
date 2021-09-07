/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/rtc_time.hpp
  ***********************************************************
**/


#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <compare>

namespace mpp::hal {

struct RtcDate {
  std::uint32_t Year;
  std::uint32_t Mounth;
  std::uint32_t Day;

  auto operator<=>(RtcDate const&) const = default;
  bool operator== (RtcDate const&) const = default;
};

struct RtcTime {
  std::uint32_t Hours;
  std::uint32_t Minutes;
  std::uint32_t Seconds;
  std::uint32_t SubSeconds;

  auto operator<=>(RtcTime const&) const = default;
  bool operator== (RtcTime const&) const = default;
};

struct RtcDateTime {
  std::uint32_t Year;
  std::uint32_t Mounth;
  std::uint32_t Day;
  std::uint32_t Hours;
  std::uint32_t Minutes;
  std::uint32_t Seconds;
  std::uint32_t SubSeconds;

  RtcDateTime
    (
      std::uint32_t aYear,  std::uint32_t aMounth,
      std::uint32_t aDay, std::uint32_t aHours,
      std::uint32_t aMinutes, std::uint32_t aSeconds,
      std::uint32_t aSubSeconds
    ): Year(aYear)
     , Mounth(aMounth)
     , Day(aDay)
     , Hours(aHours)
     , Minutes(aMinutes)
     , Seconds(aSeconds)
     , SubSeconds(aSubSeconds) {}


  RtcDateTime(RtcDate const& aDate, RtcTime const& aTime)
    : Year(aDate.Year)
    , Mounth(aDate.Mounth)
    , Day(aDate.Day)
    , Hours(aTime.Hours)
    , Minutes(aTime.Minutes)
    , Seconds(aTime.Seconds)
    , SubSeconds(aTime.SubSeconds) {}

  auto operator<=>(RtcDateTime const&) const = default;
  bool operator== (RtcDateTime const&) const = default;
  operator RtcDate() {
    return {Year, Mounth, Day};
  }
  operator RtcTime() {
    return {Hours, Minutes, Seconds, SubSeconds};
  }
};


struct Rtc {
  static void SetDateAndTime(const RtcDateTime& aDateTime);
  static void SetDateAndTime(const RtcDate& aDate, const RtcTime& aTime);
  static RtcTime NowTime();
  static RtcDate NowDate();
  static RtcDateTime NowDateTime();
};

} // namespace mpp::hal
