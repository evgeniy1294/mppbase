/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/crc_models.hpp
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>


namespace mpp::crc {

  struct BaseCrc8 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 8u;
  };

  
  
  struct BaseCrc16 {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 16u;
  };



  struct BaseCrc24 {
    using result_type = std::uint32_t;
    static constexpr std::size_t kWidth = 24u;
  };



  struct BaseCrc32 {
    using result_type = std::uint32_t;
    static constexpr std::size_t kWidth = 32u;
  };

  
  struct BaseCrc64 {
    using result_type = std::uint64_t;
    static constexpr std::size_t kWidth = 64u;
  };


    

  struct ITU_4 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 4u;
    
    static constexpr result_type kPoly   = 0x03;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x0;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x7;  
  };
    
    
    
    
    
  struct EPC_5 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 5u;
    
    static constexpr result_type kPoly   = 0x09;
    static constexpr result_type kSeed   = 0x09;
    static constexpr result_type kXorOut = 0x0;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x0;  
  };
    
    
    
    
    
  struct ITU_5 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 5u;
    
    static constexpr result_type kPoly   = 0x15;
    static constexpr result_type kSeed   = 0x0;
    static constexpr result_type kXorOut = 0x0;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x7;  
  };
        
    
    

  struct USB_5 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 5u;
    
    static constexpr result_type kPoly   = 0x05;
    static constexpr result_type kSeed   = 0x1f;
    static constexpr result_type kXorOut = 0x1f;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x19;  
  };
    
    
    
    
    
  struct CDMA2000A_6 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 6u;
    
    static constexpr result_type kPoly   = 0x27;
    static constexpr result_type kSeed   = 0x3f;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x0D;  
  };
    
    
    
    
    

  struct CDMA2000B_6 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 6u;
    
    static constexpr result_type kPoly   = 0x07;
    static constexpr result_type kSeed   = 0x3f;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x3B;  
  };
    
    
    
    
  struct DARC_6
  {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 6u;
    
    static constexpr result_type kPoly   = 0x19;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x26;
  };
    
    
    
    
  struct ITU_6
  {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 6u;
    
    static constexpr result_type kPoly   = 0x03;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x6;
  };
    
    

    
  struct CRC_7 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 7u;
    
    static constexpr result_type kPoly   = 0x09;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x75;  
  };
    
    
    
    
  struct ROHC_7 {
    using result_type = std::uint8_t;
    static constexpr std::size_t kWidth = 7u;
    
    static constexpr result_type kPoly   = 0x4f;
    static constexpr result_type kSeed   = 0x7f;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x53;  
  };
    
    
    
    
  struct CRC_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x07;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xF4;
  };




  struct CDMA2000_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x9B;
    static constexpr result_type kSeed   = 0xFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xDA;
  };




  struct DARC_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x39;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x15;
  };
  
  
  
  struct DVB_S2_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0xD5;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xBC;
  };
  



  struct EBU_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x1D;
    static constexpr result_type kSeed   = 0xFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x97;
  };
  
  
  
  
  struct I_CODE_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x1D;
    static constexpr result_type kSeed   = 0xFD;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x7E;
  };
  
  
  
  
  
  
  struct ITU_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x07;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x55;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xA1;
  };
  
  
  
  
  struct MAXIM_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x31;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0xA1;
  };
  
  
  
  
  struct ROHC_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x07;
    static constexpr result_type kSeed   = 0xFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0xD0;
  };
  
  
  
  struct WCDMA_8: public BaseCrc8
  {
    static constexpr result_type kPoly   = 0x9B;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x25;
  };
  
  
  
  
  struct CRC_10
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 10u;
    
    static constexpr result_type kPoly   = 0x233;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x199;
  };
  
  
  
  struct CDMA2000_10
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 10u;
    
    static constexpr result_type kPoly   = 0x3D9;
    static constexpr result_type kSeed   = 0x3FF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x233;
  };
  
  
  
  
  
  struct CRC_11
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 11u;
    
    static constexpr result_type kPoly   = 0x385;
    static constexpr result_type kSeed   = 0x1A;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x5A3;
  };
  
  
  
  
  struct _3GPP_12
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 12u;
    
    static constexpr result_type kPoly   = 0x80F;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0xDAF;
  };
  
  
  
  
  struct CDMA2000_12
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 12u;
    
    static constexpr result_type kPoly   = 0xF13;
    static constexpr result_type kSeed   = 0xFFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xD4D;
  };
  
  
  
  
  
  struct DECT_12
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 12u;
    
    static constexpr result_type kPoly   = 0x80F;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false; 
    static constexpr result_type kCheck = 0xF5B;
  };
  
  
  
  
  
  struct BBC_13
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 13u;
    
    static constexpr result_type kPoly   = 0x1CF5;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false; 
    static constexpr result_type kCheck = 0x4FA;
  };
  
  
  
  
  
  struct DARC_14
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 14u;
    
    static constexpr result_type kPoly   = 0x805;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;   
    static constexpr result_type kCheck = 0x82D;
  };
  
  
  
  
  
  
  struct CRC_15
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 15u;
    
    static constexpr result_type kPoly   = 0x4599;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;      
    static constexpr result_type kCheck = 0x59E;
  };
  
  
  
  
  
  struct MPT1327_15
  {
    using result_type = std::uint16_t;
    static constexpr std::size_t kWidth = 15u;
    
    static constexpr result_type kPoly   = 0x6815;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x01;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x2566;
  };
  
  
  
  
  
  
  struct ARC_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x8005;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0xBB3D;
  };
  
  
  
  
  
  
  struct AUG_CCITT_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0x1D0F;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xE5CC;
  };
  
  
  
  
  struct BUYPASS_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x8005;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false; 
    static constexpr result_type kCheck = 0xFEE8;
  };
  
  
  
  
  
  struct CCITT_FALSE_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0xFFFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x29B1;
  };
  
  
  
  
  
  
  struct CDMA2000_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0xC867;
    static constexpr result_type kSeed   = 0xFFFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x4C06;
  };
  
  
  
  
  
  struct DDS110_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x8005;
    static constexpr result_type kSeed   = 0x800D;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0x9ECF;
  };
  
  
  
  
  
  struct DECT_R_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x589;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x01;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x007E;
  };
  
  
  
  
  
  
  struct DECT_X_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x589;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false; 
    static constexpr result_type kCheck = 0x007F;
  };
  
  
  
  
  
  struct DNP_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x3D65;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0xFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true; 
    static constexpr result_type kCheck = 0xEA82;
  };
  
  
  
  
  
  struct EN_13757_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x3D65;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0xFFFF;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false; 
    static constexpr result_type kCheck = 0xC2B7;
  };
  
  
  
  
  
  struct GENIBUS_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0xFFFF;
    static constexpr result_type kXorOut = 0xFFFF;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;   
    static constexpr result_type kCheck = 0xD64E;
  };
  
  
  
  
  
  
  struct MAXIM_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x8005;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0xFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;  
    static constexpr result_type kCheck = 0x44C2;
  };
  
  
  
  
  struct MCRF4XX_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0xFFFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;   
    static constexpr result_type kCheck = 0x6F91;
  };
  
  
  
  
  
  struct RIELLO_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0xB2AA;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x63D0;
  };
  
  
  
  
  
  struct T10_DIF_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x8BB7;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xD0DB;
  };
  
  
  
  
  struct TELEDISK_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0xA097;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;
    static constexpr result_type kCheck = 0xFB3;
  };
  
  
  
  
  
  struct TMS37157_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0x89EC;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x26B1;
  };
  
  
  
  
  
  
  
  struct USB_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x8005;
    static constexpr result_type kSeed   = 0xFFFF;
    static constexpr result_type kXorOut = 0xFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true; 
    static constexpr result_type kCheck = 0xB4C8;
  };
  
  
  
  
  
  
  struct CRC_A_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0xC6C6;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0xBF05;
  };
  
  
  
  
  
  struct KERMIT_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true; 
    static constexpr result_type kCheck = 0x2189;
  };
  
  
  
  
  struct MODBUS_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x8005;
    static constexpr result_type kSeed   = 0xFFFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x4B37;
  };
  
  
  
  
  
  struct X25_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0xFFFF;
    static constexpr result_type kXorOut = 0xFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;
    static constexpr result_type kCheck = 0x906E;
  };
  
  
  
  
  
  struct XMODEM_16: public BaseCrc16
  {
    static constexpr result_type kPoly   = 0x1021;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;   
    static constexpr result_type kCheck = 0x31C3;
  };
  
  
  
  
  
  struct CRC_24: public BaseCrc24
  {
    static constexpr result_type kPoly   = 0x864CFB;
    static constexpr result_type kSeed   = 0xB704CE;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x21CF02;
  };
  
  
  
  
  
  struct FLEXRAY_A_24   : public BaseCrc24
  {
    static constexpr result_type kPoly   = 0x5D6DCB;
    static constexpr result_type kSeed   = 0xFEDCBA;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x7979BD;
  };
  
  
  
  
  
  struct FLEXRAY_B_24   : public BaseCrc24
  {
    static constexpr result_type kPoly   = 0x5D6DCB;
    static constexpr result_type kSeed   = 0xABCDEF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x1F23B8;
  };
  
  
  
  
  
  struct PHILIPS_31
  {
    using result_type = std::uint32_t;
    static constexpr std::size_t kWidth = 31u;
    
    static constexpr result_type kPoly   = 0x4C11DB7;
    static constexpr result_type kSeed   = 0x7FFFFFFF;
    static constexpr result_type kXorOut = 0x7FFFFFFF;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;      
    static constexpr result_type kCheck = 0xCE9E46C; 
  };
  
  
  
  
  
  struct ZLIB_32: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0x4C11DB7;
    static constexpr result_type kSeed   = 0xFFFFFFFF;
    static constexpr result_type kXorOut = 0xFFFFFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;  
    static constexpr result_type kCheck = 0xCBF43926;
  };
  
  
  
  
  
  struct BZIP_32: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0x4C11DB7;
    static constexpr result_type kSeed   = 0xFFFFFFFF;
    static constexpr result_type kXorOut = 0xFFFFFFFF;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0xFC891918;
  };
  
  
  
  
  struct CRC_32C: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0x1EDC6F41;
    static constexpr result_type kSeed   = 0xFFFFFFFF;
    static constexpr result_type kXorOut = 0xFFFFFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;  
    static constexpr result_type kCheck = 0xE3069283;  
  };
  
  
  
  
  
  struct CRC_32D: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0xA833982B;
    static constexpr result_type kSeed   = 0xFFFFFFFF;
    static constexpr result_type kXorOut = 0xFFFFFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;  
    static constexpr result_type kCheck = 0x87315576;  
  };
  
  
  
  
  
  struct MPEG2_32: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0x4C11DB7;
    static constexpr result_type kSeed   = 0xFFFFFFFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x376E6E7;  
  };
  
  
  
  
  
  struct POSIX_32: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0x4C11DB7;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0xFFFFFFFF;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x765E7680;  
  };
  
  
  
  
  
  struct CRC_32Q: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0x814141AB;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x3010BF7F;  
  };
  
  
  
  
  
  
  
  struct JAMCRC_32: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0x4C11DB7;
    static constexpr result_type kSeed   = 0xFFFFFFFF;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;  
    static constexpr result_type kCheck = 0x340BC6D9;  
  };
  
  
  
  
  
  
  struct XFER_32: public BaseCrc32
  {
    static constexpr result_type kPoly   = 0xAF;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0xBD0BE338;  
  };
  
  
  
  
  
  
  struct GSM_40
  {
    using result_type = std::uint64_t;
    static constexpr std::size_t kWidth = 40u;
    
    static constexpr result_type kPoly   = 0x4820009;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0xFFFFFFFFFF;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0xD4164FC646;  
  };
  
  
  
  
  
  struct CRC_64: public BaseCrc64
  {
    static constexpr result_type kPoly   = 0x42F0E1EBA9EA3693;
    static constexpr result_type kSeed   = 0x00;
    static constexpr result_type kXorOut = 0x00;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x6C40DF5F0B497347;  
  };
  
  
  
  
  
  
  struct WE_64: public BaseCrc64
  {
    static constexpr result_type kPoly   = 0x42F0E1EBA9EA3693;
    static constexpr result_type kSeed   = 0xFFFFFFFFFFFFFFFF;
    static constexpr result_type kXorOut = 0xFFFFFFFFFFFFFFFF;
    static constexpr bool kRefIn  = false;
    static constexpr bool kRefOut = false;  
    static constexpr result_type kCheck = 0x62EC59E3F1A4F00A;  
  };
  
  
  
  
  
  struct XZ_64: public BaseCrc64
  {
    static constexpr result_type kPoly   = 0x42F0E1EBA9EA3693;
    static constexpr result_type kSeed   = 0xFFFFFFFFFFFFFFFF;
    static constexpr result_type kXorOut = 0xFFFFFFFFFFFFFFFF;
    static constexpr bool kRefIn  = true;
    static constexpr bool kRefOut = true;  
    static constexpr result_type kCheck = 0x995DC9BBDF1939FA;  
  };
  
    
} // namespace crc 








