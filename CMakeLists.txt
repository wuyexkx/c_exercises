cmake_minimum_required(VERSION 2.8.1)
project(c_exercises)
# add_compile_options(-std=c++11)

include_directories(./include)
# aux_source_directory(./src SRC)
# add_library(${PROJECT_NAME} ${SRC})

add_executable(test_linux_list test_linux_list.c)
# target_link_libraries(main ${PROJECT_NAME})