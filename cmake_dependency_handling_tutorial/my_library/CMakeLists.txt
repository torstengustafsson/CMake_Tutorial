# contains a bunch of code that otheers can use, be it 
# implementations (executables) or other libraries

# set headers
set(header header-a.hpp
		   header-b.hpp
		   config.hpp )

# set source files
set(src src-a.cpp
		src-b.cpp )
		
# configure config.hpp.in
configure_file("config.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp")

# define library target
add_library(my_library ${header} ${src})

# add include directories
target_include_directories(my_library PUBLIC ${MY_LIBRARY_SOURCE_DIR}/my_library
											 ${CMAKE_CURRENT_BINARY_DIR})
#or (not currently working):
# use generator expressions to be able to set include directories for 
# external CMake projects that uses this library
#target_include_directories(my_library PUBLIC
#                       $<BUILD_INTERFACE:${MY_LIBRARY_SOURCE_DIR}/include> # for headers when building
#                       $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for config_impl.hpp when building
#                       $<INSTALL_INTERFACE:${include_dest}> # for client in install mode
#                       $<INSTALL_INTERFACE:${lib_dest}>) # for config_impl.hpp in install mode

# create lib files
install(TARGETS my_library DESTINATION "${main_lib_dest}")
# or (not currently working):
# creates .cmake file as well, which makes it easy to include this project
# in other CMake projects
#install(TARGETS my_library EXPORT my_library DESTINATION "${lib_dest}")


install(FILES ${header} DESTINATION "${include_dest}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${include_dest}")

# my_library-config.cmake - package configuration file
#get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
#include(${CMAKE_CURRENT_BINARY_DIR}/cmake_install.cmake)
