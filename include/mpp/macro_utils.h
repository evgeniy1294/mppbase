#pragma once

#include "macro_helper.h"

/**
  * @addtogroup base-macros
  *
  * @brief
  *   This module defines macros for parsing variadic arguments.
  *
  * @{
  */



/**
  * This macro returns the first argument in a list of input arguments.
  * 
  * @param[in] ...   A list of arguments (MUST contain at least one).
  * @returns The first argument in the given list of input arguments.
  */
#define MPP_FIRST_ARG(...) _MPP_HELPER_GET_FIRST_ARG(__VA_ARGS__, JUNK)





/**
 * This macro returns the second argument in a list of input arguments if any.
 * 
 * @param[in] ...   A list of arguments (MUST contain either one or two arguments).
 * @returns The second argument if any.
 */
#define MPP_SECOND_ARG(...) _MPP_HELPER_GET_SECOND_ARG(_MPP_HELPER_HAS_ONE_ARG_OR_TWO_ARGS(__VA_ARGS__), __VA_ARGS__)





/**
  * This macro calculates the number of elements in an array.
  * 
  * @param[in] aArray  Name of the array variable.
  * @returns Number of elements in the array.
  */
#define MPP_ARRAY_LENGTH(aArray) (sizeof(aArray) / sizeof(aArray[0]))





/**
  * This macro returns a pointer to end of a given array (pointing to the past-the-end element).
  *
  * @note The past-the-end element is a theoretical element that would follow the last element in the array. It does
  * not point to an actual element in array, and thus should not be dereferenced.
  *
  * @param[in]    Name of the array variable
  * @returns Pointer to the past-the-end element.
  */
#define MPP_ARRAY_END(aArray) (&aArray[MACRO_ARRAY_LENGTH(aArray)])





/**
  * This macro returns remainder of a division 
  *
  */ 
#define MACRO_MOD(x, m) ((((x) % (m)) + (m)) % (m))





/**
 * This macro returns the smaller of @p x and @p y.
 *
 */
#define MPP_MIN(x, y) ((y) < (x) ? (y) : (x))





/**
  * This macro returns the greater of @p x and @p y.
  *
  */
#define MPP_MAX(x, y) ((y) > (x) ? (y) : (x))





/**
  * This macro create uint32_t value from bytes
  *
  */
#define MPP_MAKE_U32(a,b,c,d) (((uint32_t)((a) & 0xff) << 24) | \
                               ((uint32_t)((b) & 0xff) << 16) | \
                               ((uint32_t)((c) & 0xff) << 8)  | \
                                (uint32_t)((d) & 0xff))





/**
  * This macro checks for the specified status, which is expected to commonly be successful, and branches to the local
  * label 'exit' if the status is unsuccessful.
  *
  * @note: Taked from OpenThread project
  *
  * @param[in]  aStatus     A scalar status to be evaluated against zero (0).
  *
  */
#define mfSuccessOrExit(aStatus) \
  do                             \
  {                              \
    if ((aStatus) != 0)          \
    {                            \
      goto exit;                 \
    }                            \
  } while (false)
  
  
  

  
  
/**                                                                                                                                                                                       
  * This macro checks for the specified condition, which is expected to commonly be true, and both executes @a ... and                                                                     
  * branches to the local label 'exit' if the condition is false.
  *
  * @note: Taked from OpenThread project
  *
  * @param[in]  aCondition  A Boolean expression to be evaluated.
  * @param[in]  aAction     An optional expression or block to execute when the assertion fails.
  *
  */
#define mfVerifyOrExit(...)                 \
  do                                        \
  {                                         \
    if (!(MACRO_FIRST_ARG(__VA_ARGS__)))    \
    {                                       \
      MPP_SECOND_ARG(__VA_ARGS__);          \
      goto exit;                            \
    }                                       \
  } while (false)
  
  

  
  
/**
  * This macro unconditionally executes @a ... and branches to the local label 'exit'.
  *
  * @note The use of this interface implies neither success nor failure for the overall exit status of the enclosing
  *       function body.
  *
  * Note: Taked from OpenThread project
  *
  * @param[in]  ...         An optional expression or block to execute when the assertion fails.
  *
  */
#define mfExitNow(...)    \
   do                     \
   {                      \
      __VA_ARGS__;        \
      goto exit;          \
   } while (false)
   
   
   
   
   
/**
  * This macro executes the `statement` and ignores the return value.
  *
  * This is primarily used to indicate the intention of developer that the return value of a function/method can be
  * safely ignored.
  * 
  * @note: Taked from OpenThread project
  *
  * @param[in]  aStatement  The function/method to execute.
  *
  */
#define mfIgnoreReturnValue(aStatement)  \
  do                                     \
  {                                      \
    if (aStatement)                      \
    {                                    \
    }                                    \
  } while (false)
  
  



/** @} */

