cmake_minimum_required(VERSION 3.0)
project (sat-slam)

if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug)
endif()

message("CMAKE_BUILD_TYPE: "${CMAKE_BUILD_TYPE})

# find_package(OpenCV)# 3.2.0 EXACT REQUIRED)
# find_package (Eigen3 REQUIRED)

set(CMAKE_CXX_FLAGS "-Wall")
 
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    # ${PROJECT_SOURCE_DIR}/external/image-align/include
    # ${PROJECT_SOURCE_DIR}/external/ELSED/include
    # ${PROJECT_SOURCE_DIR}/external/anms/include
    # ${OpenCV_INCLUDE_DIR}
)

link_directories(${PROJECT_SOURCE_DIR}/external/ELSED/lib)

add_executable(hello main.cpp)
# target_link_libraries(hello ${OpenCV_LIBS} Eigen3::Eigen) # elsed)


