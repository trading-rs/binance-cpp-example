cmake_minimum_required(VERSION 3.1)
project(binance-trading)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(BINANCE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/binance-cpp/include)

set(BUILD_CPR_TESTS OFF CACHE BOOL "Don't build cpr tests")
set(BUILD_BINANCE_EXEC OFF CACHE BOOL "Don't build binance exec")
set(BUILD_BINANCE_TESTS OFF CACHE BOOL "Don't build binance tests")

add_subdirectory(binance-cpp)

include_directories(
  ${RANGEV3_INCLUDE_DIR}
  ${FMT_INCLUDE_DIR}
  ${CPR_INCLUDE_DIR}
  ${JSON_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CRYPTO_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
  ${BEAST_INCLUDE_DIR}
  ${SPDLOG_INCLUDE_DIR}
  ${BINANCE_INCLUDE_DIR}
  ${FP_INCLUDE_DIR}
  ${DERIVEJSON_INCLUDE_DIR}
  )

SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
set(Boost_USE_STATIC_LIBS ON)
find_package(
  Boost
  COMPONENTS
  system
  random
  thread
  REQUIRED)
link_directories(
  ${Boost_LIBRARY_DIR}
  ${OPENSSL_LIBRARIES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
add_executable(main main.cc)
target_link_libraries(
  main
  ${OPENSSL_LIBRARIES}/libssl.a
  ${OPENSSL_LIBRARIES}/libcrypto.a
  ${Boost_LIBRARIES}
  ${CPR_LIBRARIES}
  "-ldl"
  Threads::Threads
  )