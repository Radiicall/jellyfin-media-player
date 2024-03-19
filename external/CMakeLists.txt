set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS_THIRD_PARTY}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_FLAGS_THIRD_PARTY}")


enable_language(Rust)

add_subdirectory(jellyfin-rpc)

include_directories("jellyfin-rpc/include")

if(APPLE)
  add_subdirectory(plistparser)
  add_subdirectory(SPMediaKeyTap)
  add_subdirectory(HIDRemote)
  add_subdirectory(letsmove)
endif(APPLE)
