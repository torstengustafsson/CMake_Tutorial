# this is an implementation that uses my_library
# it can find my_library either using target_link_libraries 
# and target_include_directories, or with find_package

# set source files
set(src example-a.cpp )

# define library target
add_executable(example-a ${src})
target_link_libraries(example-a PUBLIC my_library)
target_include_directories(example-a PUBLIC ${MY_LIBRARY_SOURCE_DIR}/inc
											 ${CMAKE_CURRENT_BINARY_DIR})
install(TARGETS example-a DESTINATION "${bin_dest}")
