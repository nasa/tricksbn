cmake_minimum_required(VERSION 2.8.12)

project(protobetterdynamic CXX)

include_directories(include)
set(SRC_FILES src/protobetterdynamic.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DPROTOBETTER_DYNAMIC_LIB_LIBRARY)

add_library(protobetterdynamic SHARED ${SRC_FILES})

find_package(PkgConfig REQUIRED)

pkg_check_modules(JSONCPP jsoncpp)
include_directories(${JSONCPP_INCLUDE_DIRS})
target_link_libraries(protobetterdynamic ${JSONCPP_LIBRARIES})

include_directories(/usr/include/libxml2)
set(LIBXML2_LIBRARIES ${LIBXML2_LIBRARIES} libxml2.so)
target_link_libraries(protobetterdynamic ${LIBXML2_LIBRARIES})

