#pragma once

/**
 * @file
 *   This file includes compile-time configuration constants for framework.
 */



/**
 * @def MPP_CONFIG_FILE
 *
 * The MPP feature configuration file.
 *
 */
#if !defined(MPP_CONFIG_FILE)
  #define MPP_CONFIG_FILE "mpp_config_generic.h"
#endif

#include MPP_CONFIG_FILE



#include "core_default_config.h"


