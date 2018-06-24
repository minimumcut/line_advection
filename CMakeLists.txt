cmake_minimum_required(VERSION 3.1.0)
project(Threesketch VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(EIGEN_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/eigen-git-mirror/)
include_directories(${EIGEN_INCLUDE_PATH})

add_subdirectory(lib)
add_subdirectory(src)