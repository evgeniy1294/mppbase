#include <mpp/platform/logging.h>
#include <iostream>
#include <string>


#ifdef __cplusplus
extern "C" {
#endif
    
    
void mppPlatLog( mppLogLevel aLogLevel, const char *aLogLine )
{
  std::cout << aLogLine << std::endl;   
}


#ifdef __cplusplus
}
#endif
