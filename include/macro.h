#pragma once


/**
  * This macro calculates the number of elements in an array.
  * @param[in] aArray  Name of the array variable.
  * @returns Number of elements in the array.
  */
#define MPP_ARRAY_LENGTH(aArray) (sizeof(aArray) / sizeof(aArray[0]))




/**
  * This macro returns a pointer to end of a given array (pointing to the past-the-end element).
  *
  * Note that the past-the-end element is a theoretical element that would follow the last element in the array. It does
  * not point to an actual element in array, and thus should not be dereferenced.
  *
  * @param[in] Name of the array variable
  *
  * @returns Pointer to the past-the-end element.
  *
  */
#define MPP_ARRAY_END(aArray) (&aArray[MACRO_ARRAY_LENGTH(aArray)])





/**
  * This macro create uint32_t value from bytes
  * @param[in] a four byte
  * @param[in] b third byte
  * @param[in] c second byte
  * @param[in] d first byte
  */
#define MPP_MAKE_U32(a,b,c,d) (((uint32_t)((a) & 0xff) << 24) | \
                               ((uint32_t)((b) & 0xff) << 16) | \
                               ((uint32_t)((c) & 0xff) << 8)  | \
                                (uint32_t)((d) & 0xff))






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
