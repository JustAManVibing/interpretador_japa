cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
project(interpretador_japa)
add_executable(japa src/japa.cpp src/numero.cpp src/operacoes.cpp src/palavra.cpp)
target_include_directories(japa PRIVATE include)
add_custom_target(run
    COMMAND $<TARGET_FILE:japa> "codigo_japa/1.jpa"
    DEPENDS japa
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    
)