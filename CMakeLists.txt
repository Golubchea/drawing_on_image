cmake_minimum_required(VERSION 3.1)

#name of project in directory
get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})





#############
#memleak detection detect with

#valgrind --leak-check=full ./v
##############


#set bin dir to compile
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories( ${PROJECT_SOURCE_DIR}/include)


file (GLOB_RECURSE SRC_LIST src/*.cpp src/*.c    )

 
include_directories(include)
 



    add_executable(${PROJECT_NAME} ${SRC_LIST})
    target_link_libraries(${PROJECT_NAME} m)

