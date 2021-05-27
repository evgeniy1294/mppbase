/**
 * @file
 *   This file implements the mpp error code functions.
 */


#include "common/error.hpp"


const char *mppErrorToString(mppError aError)
{
  return mpp::ErrorToString(aError);
}



