#pragma once


/**
 * @file
 * @brief
 *   This file includes the platform abstraction for the debug log service.
 */


#include <stdarg.h>
#include <stdint.h>



#ifdef __cplusplus
extern "C" {
#endif
  
  
 /**
 * @addtogroup plat-logging
 *
 * @brief
 *   This module includes the platform abstraction for the debug log service.
 *
 * @{
 *
 */

  
/**
 * This function outputs logs.
 *
 * @note Taked from OpenThread
 * @param[in]  aFormat     A pointer to the string.
 *
 */
void mppPlatLog( const char *aLogLine );


  
/**
 * @}
 *
 */

#ifdef __cplusplus
} // extern "C"
#endif

