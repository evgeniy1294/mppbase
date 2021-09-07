/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/systick.hpp
  ***********************************************************
**/


#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

namespace mpp::hal {

class Systick {
public:
  constexpr static std::uint32_t TickPerSec = 1000u;

  static void Init();
  static void Interrupt();
  static std::uint32_t Now();
};

} // namespace mpp::hal
