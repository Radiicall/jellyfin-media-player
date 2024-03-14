#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

struct Discord {
  DiscordIpcClient client;
};

template<typename T, typename E>
struct CResult {
  enum class Tag {
    Ok,
    Err,
  };

  struct Ok_Body {
    T _0;
  };

  struct Err_Body {
    E _0;
  };

  Tag tag;
  union {
    Ok_Body ok;
    Err_Body err;
  };
};

extern "C" {

CResult<Discord, uintptr_t> new(const char *client_id);

uintptr_t add(uintptr_t left, uintptr_t right);

void connect(Discord *discord);

} // extern "C"
