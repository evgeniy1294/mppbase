#pragma once


#include <mpp/config/core_config.h>

#include <ctype.h>
#include <stdio.h>


#if MPP_CONFIG_ASSERT_ENABLE


#if MPP_CONFIG_PLATFORM_ASSERT_MANAGEMENT
  #include "mpp/platform/assert.h"
  
  #ifndef FILE_NAME
    #define FILE_NAME __FILE__
  #endif

  #define MPP_ASSERT(cond)                         \
    do                                             \
    {                                              \
      if (!(cond))                                 \
      {                                            \
        mppPlatAssertFail(FILE_NAME, __LINE__);    \
        while (1)                                  \
        {                                          \
        }                                          \
      }                                            \
    } while(0)                                     
  
#elif defined (__linux__)

  #include <assert.h>
  #define MPP_ASSERT(cond) assert(cond)
  
#else  

  #define MPP_ASSERT(cond) \
    do                     \
    {                      \
        if (!(cond))       \
        {                  \
            while (1)      \
            {              \
            }              \
        }                  \
    } while (0)  


#endif // MPP_CONFIG_PLATFORM_ASSERT_MANAGEMENT
  
  
  
#endif // MPP_CONFIG_ASSERT_ENABLE


