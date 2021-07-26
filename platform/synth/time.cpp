#include <cstdint>
#include <chrono>


#ifdef __cplusplus
extern "C" {
#endif


uint32_t GetSystemTickMs() {
  using namespace std::chrono;

  time_point<std::chrono::system_clock> now = system_clock::now();

  auto duration = now.time_since_epoch();
  auto millis   = duration_cast<std::chrono::milliseconds>(duration).count();

  return millis;
}


#ifdef __cplusplus
}
#endif


