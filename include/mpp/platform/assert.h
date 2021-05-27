#pragma once

/**
 * @file
 * @brief
 *   This file includes platform abstractions for assert functions.
 */

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif
  
  
/**
 * This function provides a platform specific implementation for assert.
 *
 * @param[in] aFilename    The name of the file where the assert occurred.
 * @param[in] aLineNumber  The line number in the file where the assert occurred.
 * 
 * @note Taked from OpenThread project.
 *
 */
void mppPlatAssertFail(const char *aFilename, int aLineNumber);  
  
  
  
  
#ifdef __cplusplus
} // extern "C"
#endif
