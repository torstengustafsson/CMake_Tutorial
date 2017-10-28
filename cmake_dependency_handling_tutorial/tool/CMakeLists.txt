# can be used for various tools for the project


# set source files
set(src tool.cpp )

# define library target
add_library(my_library_tool ${src})
target_include_directories(my_library_tool PUBLIC ${MY_LIBRARY_SOURCE_DIR}/my_library
											      ${CMAKE_CURRENT_BINARY_DIR})

# needed to for find_package
install(TARGETS my_library_tool DESTINATION "${bin_dest}")
