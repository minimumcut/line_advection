cmake_minimum_required(VERSION 3.1.0)
project(Threesketch VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-m64") 

set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})

set(EIGEN_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/eigen-git-mirror/)
include_directories(${EIGEN_INCLUDE_PATH})

set(TINYEXR_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/lib/tinyexr/)
include_directories(${TINYEXR_INCLUDE_PATH})

add_subdirectory(lib)
add_subdirectory(src)