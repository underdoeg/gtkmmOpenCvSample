include(FindPkgConfig)

##############################################

project(StGallenBgRemoval)
cmake_minimum_required(VERSION 2.8)


pkg_check_modules(PKG REQUIRED gtkmm-3.0)

include_directories(${PKG_INCLUDE_DIRS})
link_libraries(${PKG_LIBRARIES} opencv_core opencv_videoio opencv_imgproc pthread)
link_directories(${PKG_LIBRARY_DIRS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


aux_source_directory(src/ SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
