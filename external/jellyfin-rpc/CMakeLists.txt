include(ExternalProject)

ExternalProject_add(
    libjellyfin_rpc
    DOWNLOAD_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND cargo build COMMAND cargo build --release
    BINARY_DIR "${CMAKE_SOURCE_DIR}/external/jellyfin-rpc"
    INSTALL_COMMAND ""
    LOG_BUILD ON)
