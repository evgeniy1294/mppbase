#pragma once


/**
 * @file
 *   This file includes default compile-time configuration constants for MPP
 */




/**
 * @def MPP_CONFIG_STACK_VERSION_MAJOR
 *
 * The Framework Version Major.
 *
 */
#ifndef MPP_CONFIG_STACK_VERSION_MAJOR
  #define MPP_CONFIG_STACK_VERSION_MAJOR 0
#endif





/**
 * @def MPP_CONFIG_STACK_VERSION_MINOR
 *
 * The Framework Version Minor.
 *
 */
#ifndef MPP_CONFIG_STACK_VERSION_MINOR
  #define MPP_CONFIG_STACK_VERSION_MINOR 1
#endif





/**
 * @def MPP_CONFIG_ASSERT_ENABLE
 *
 * Define as 1 to enable assert function `MPP_ASSERT()` within MPP code and its libraries.
 *
 */
#ifndef MPP_CONFIG_ASSERT_ENABLE
  #define MPP_CONFIG_ASSERT_ENABLE     1
#endif




/**
 * @def MPP_CONFIG_PLATFORM_ASSERT_MANAGEMENT
 *
 * Define as 1 to use platform specific assert function.
 *
 */
#ifndef MPP_CONFIG_PLATFORM_ASSERT_MANAGEMENT
  #define MPP_CONFIG_PLATFORM_ASSERT_MANAGEMENT    0
#endif



/**
 * @def MPP_CONFIG_LOG_PREPEND_LEVEL
 *
 * Define as 1 to use log level prefix string definitions.
 *
 */
#ifndef MPP_CONFIG_LOG_PREPEND_LEVEL
  #define MPP_CONFIG_LOG_PREPEND_LEVEL    1
#endif


/**
 * @def MPP_CONFIG_LOG_PREPEND_LEVEL
 *
 * Define log string max length.
 *
 */
#ifndef MPP_CONFIG_LOG_MAX_SIZE
  #define MPP_CONFIG_LOG_MAX_SIZE 30
#endif

