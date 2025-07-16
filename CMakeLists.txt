cmake_minimum_required(VERSION 3.10)
project(mhtools)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Crypto++
find_package(PkgConfig REQUIRED)
pkg_check_modules(CRYPTO_PP REQUIRED libcrypto++)
include_directories(${CRYPTO_PP_INCLUDE_DIRS})

# Add libkirk
add_subdirectory(libkirk)
include_directories(libkirk)

# Add executable
add_executable(mhtools src/cpp/main.cpp)

# Link libraries
target_link_libraries(mhtools ${CRYPTO_PP_LIBRARIES} kirk)
