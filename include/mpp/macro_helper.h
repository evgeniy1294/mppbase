/**
 * @file
 *   This file includes private helpers for framework
 */


#pragma once


/**
  * @addtogroup base-macros-helpers
  *
  * @brief
  *   This module defines macros for parsing variadic arguments. 
  * @note 
  *   Not for user-space code.
  * 
  * @{
  */


#define _MPP_HELPER_GET_FIRST_ARG(aFirst, ...) aFirst

#define _MPP_HELPER_GET_SECOND_ARG(aNum, ...) _MPP_HELPER_GET_SECOND_APPEND_NUM_ARGS(aNum, __VA_ARGS__)
#define _MPP_HELPER_GET_SECOND_APPEND_NUM_ARGS(aNum, ...) _MPP_HELPER_GET_SECOND_WITH_##aNum(__VA_ARGS__)
#define _MPP_HELPER_GET_SECOND_WITH_ONE_ARG(aFirst)
#define _MPP_HELPER_GET_SECOND_WITH_TWO_ARGS(aFirst, aSecond) aSecond

#define _MPP_HELPER_HAS_ONE_ARG_OR_TWO_ARGS(...) _MPP_HELPER_SELECT_3(__VA_ARGS__, TWO_ARGS, ONE_ARG, JUNK)
#define _MPP_HELPER_SELECT_3(a1, a2, a3, ...) a3



/** @} */
