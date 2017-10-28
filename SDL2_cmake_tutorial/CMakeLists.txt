cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SDL2_DIR ${CMAKE_SOURCE_DIR}/ext/SDL2-2.0.7)
set(SDL2_image_DIR ${CMAKE_SOURCE_DIR}/ext/SDL2_image-2.0.2)
set(SDL2_ttf_DIR ${CMAKE_SOURCE_DIR}/ext/SDL2_ttf-2.0.14)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

add_executable(SDL2Test Main.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})