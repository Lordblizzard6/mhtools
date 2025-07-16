cmake_minimum_required(VERSION 3.10)
project(mhtools_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Crypto++
find_package(PkgConfig REQUIRED)
pkg_check_modules(CRYPTO_PP REQUIRED libcrypto++)
include_directories(${CRYPTO_PP_INCLUDE_DIRS})

# Add libkirk
add_subdirectory(../libkirk ${CMAKE_CURRENT_BINARY_DIR}/libkirk)
include_directories(../libkirk ../src/cpp/include)

# Add test executable
add_executable(mhtools_tests test_kirk.cpp ../src/cpp/kirk_cypher.cpp)

# Link libraries
target_link_libraries(mhtools_tests ${CRYPTO_PP_LIBRARIES} kirk)

# Add Catch2
include_directories(.)
