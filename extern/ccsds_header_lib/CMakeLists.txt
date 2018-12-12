cmake_minimum_required(VERSION 2.8.12)

project(ccsds_header_lib_test C CXX)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CCSDS_HEADER_LIB_TEST_INC
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(CCSDS_HEADER_LIB_TEST_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cfe/cfe_sb_msg_id_util.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test_main.cpp
)

add_executable(${PROJECT_NAME} ${CCSDS_HEADER_LIB_TEST_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${CCSDS_HEADER_LIB_TEST_INC})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
