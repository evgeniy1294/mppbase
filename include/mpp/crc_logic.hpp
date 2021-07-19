/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/crc_logic.hpp
  ***********************************************************
**/


#pragma once



//____________________INCLUDE_____________________//
#include <cstdint>
#include <array>
#include <type_traits>
#include <limits>




namespace mpp::crc {
  
  template< class Model >
  class Logic final {
    static_assert(::std::is_same_v< Model, ::std::decay_t< decltype(Model()) > >);
    static_assert((Model::kWidth <= sizeof(typename Model::result_type) * 8), "Fields 'result_type' and 'kWidth' is incorrect");
    static_assert((Model::kWidth >= 4), "Fields 'kWidth' must be greater or equal 4");
    
    public:
      using result_type = typename Model::result_type;
    
      static constexpr std::size_t kWidth  = Model::kWidth;
      static constexpr result_type kPoly   = Model::kPoly;
      static constexpr result_type kSeed   = Model::kSeed;
      static constexpr result_type kXorOut = Model::kXorOut;
      static constexpr bool kRefIn  = Model::kRefIn;
      static constexpr bool kRefOut = Model::kRefOut;
      static constexpr result_type kResultMask = std::numeric_limits< result_type >::max() >> ( sizeof( result_type )*8u - kWidth);
        
    private:
      std::array< result_type, 16 > Table;
      result_type crc = Model::kSeed;
    
    
    public:
      constexpr Logic() noexcept(true)
      {
        constexpr result_type kRefPoly = mpp::utils::Reflect<result_type, kWidth>(Model::kPoly);
        constexpr result_type mask = (kRefIn) ? static_cast<result_type>(1u) : 
                                                static_cast<result_type>(1u) << ( kWidth - 1u );
        
        for (std::size_t i = 0u; i < Table.size(); i++) {
          result_type x = 0;
          
          if constexpr (kRefIn)
          {
            for (std::size_t j = 0x01; j < 0x10; j <<= 1) {
              bool bit = x & mask;
              bit = ( i & j ) ? !bit : bit;
              x = (bit) ? (x >> 1) ^ kRefPoly : (x >> 1);
            }
          }
          else
          {
            for (std::size_t j = 0x08; j > 0; j >>= 1) {
              bool bit = x & mask;
              bit = ( i & j ) ? !bit : bit;
              x = (bit) ? (x << 1) ^ kPoly : (x << 1);
            }
            
          }
          
          Table[i] = x & kResultMask;
        }       
      }
      
      
      
      
      inline result_type Finalize( ) noexcept(true)
      {
        if constexpr (kRefIn)
        {  
          if constexpr (!kRefOut)
            crc = mpp::utils::Reflect<result_type, kWidth>(crc);
        }
        else
        {
          if constexpr (kRefOut)
            crc = mpp::utils::Reflect<result_type, kWidth>(crc);   
        }
        
        result_type tmp = crc;
        crc = kSeed;
          
        return (tmp ^ kXorOut) & kResultMask;
      }
      
      
      
    
      template< typename T >
      void Calculate( const T* data, const T* end ) noexcept(true)
      { 
        const std::uint8_t* ptr = reinterpret_cast< const std::uint8_t* >( data );

        if constexpr (kRefIn)
        { 
          while ( ptr < reinterpret_cast< const std::uint8_t* >( end ) ) {
            crc = crc ^ ( static_cast < result_type >(*ptr++) << 0 );
              
            crc = (crc >> 4u) ^ Table[ crc & 0b1111u ];
            crc = (crc >> 4u) ^ Table[ crc & 0b1111u ];
          }
        }
        else
        {
          constexpr std::size_t shift_data = (kWidth < 8) ? kWidth - 4 : kWidth - 8u;
            
          while ( ptr < reinterpret_cast< const std::uint8_t* >( end ) ) {
            if constexpr ( kWidth  < 8 ) {
              std::size_t tbl_idx = (crc >> shift_data) ^ (*ptr >> 4);
              crc = (crc << 4u) ^ Table[ tbl_idx & 0b1111 ];
             
              tbl_idx = (crc >> shift_data) ^ (*ptr++);
              crc = (crc << 4u) ^ Table[ tbl_idx & 0b1111 ];
            }
            else
            {
              constexpr std::size_t shift_idx = kWidth - 4;
                            
              crc = crc ^ ( static_cast < result_type >(*ptr++) << shift_data );
  
              crc = (crc << 4u) ^ Table[ ( crc >> shift_idx ) & 0b1111 ];
              crc = (crc << 4u) ^ Table[ ( crc >> shift_idx ) & 0b1111 ];
            }
          }
        }
          
        return;
      }
    
      
  };
    
   
} // namespace crc 








