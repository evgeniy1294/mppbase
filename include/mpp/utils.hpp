/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/utils.hpp
  ***********************************************************
**/

#pragma once

#include <cmath>
#include <limits>

namespace mpp {


  template < typename T, std::size_t bits = sizeof(T) * 8 > 
  inline constexpr T Reflect ( T x )
  {
    T reflection = 0;
    constexpr T one = 1; 
  
    for ( std::size_t i = 0 ; i < bits ; ++i, x >>= 1 )
    {
      if ( x & one )
        reflection |= ( one << (bits - 1u - i) );
    }
        
    return reflection;
  }


  inline
  bool IsFuzzyEqual( float aFirst, float aSecond, float aEpsilon )
  {
    return (std::fabs(aFirst - aSecond) <= aEpsilon);
  }

  inline
  bool IsFuzzyEqual( float aFirst, float aSecond )
  {
    static constexpr auto epsilon = 1.0e-05f;

    if (std::fabs(aFirst - aSecond) <= epsilon)
      return true;

    return std::fabs(aFirst - aSecond) <= epsilon * std::fmax(std::fabs(aFirst), std::fabs(aSecond));
  }


  inline
  bool IsFuzzyNull( float aValue, float aEpsilon = 1.0e-05f )
  {
    return (std::fabs(aValue) < aEpsilon);
  }
}  // namespace mpp 

