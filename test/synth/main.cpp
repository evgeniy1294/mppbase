#include <cstdint>
#include <cstring>
#include <iostream>
#include <mpp/logging.h>

static const char* sPrefix = "[MAIN]";

int main()
{
  mppLogCrit( sPrefix, "%s", "LOG!!!");
  return 0; 
}
