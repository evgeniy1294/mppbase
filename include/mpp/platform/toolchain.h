#pragma once

/**
  * @addtogroup macro-toolchain
  *
  * @brief
  *   This module defines a toolchain abstraction layer through macros.
  *
  */


#include <stdbool.h>


/**
  * @def MPP_TOOL_WEAK
  *
  * Compiler-specific weak symbol modifier.
  *
  */
#if defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM) || defined(__TI_ARM__)
  #define MPP_TOOL_WEAK   __attribute__((weak))
  
#elif defined(__ICCARM__) || defined(__ICC8051__)
  #define MPP_TOOL_WEAK __weak
  
#else
  // Symbols for Doxygen
  #define MPP_TOOL_WEAK
  #error "Error: No valid Toolchain specified"
#endif






/**
 * @def MPP_UNUSED_VARIABLE
 *
 * Suppress unused variable warning in specific toolchains.
 *
 */
#if defined(__ICCARM__)

  #include <stddef.h>

  #define MPP_UNUSED_VARIABLE(VARIABLE) \
    do                                    \
    {                                     \
      if (&VARIABLE == NULL)              \
      {                                   \
      }                                   \
    } while (false)   
        
        
#elif defined(__CC_ARM)

  #include <stddef.h>

  #define MPP_UNUSED_VARIABLE(VARIABLE) \
      do                                  \
      {                                   \
          if (&VARIABLE == NULL)          \
          {                               \
          }                               \
      } while (false)        
      
#elif defined(__TI_ARM__)

  #include <stddef.h>

  #define MPP_UNUSED_VARIABLE(VARIABLE) \
    do                                    \
    {                                     \
      if (&VARIABLE == NULL)              \
      {                                   \
      }                                   \
    } while (false)

#else

  #define MPP_UNUSED_VARIABLE(VARIABLE) \
    do                                    \
    {                                     \
      (void)(VARIABLE);                   \
    } while (false)      
    
#endif

    
    
/*
 * Keil and IAR compiler doesn't provide type limits for C++.
 */
#ifdef __cplusplus
  #if defined(__CC_ARM) || defined(__ICCARM__)

    #ifndef UINT8_MAX
      #define UINT8_MAX 0xff
    #endif

    #ifndef UINT16_MAX
      #define UINT16_MAX 0xffff
    #endif

  #endif
#endif


