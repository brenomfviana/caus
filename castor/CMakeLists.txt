cmake_minimum_required(VERSION 3.13)

include(FetchContent)

project(castor
  VERSION 1.0.0
  DESCRIPTION "CASTOR is a cellular automata simulator"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# ---------------------------------------------------------------------------- #
# Dependencies
# ---------------------------------------------------------------------------- #

FetchContent_Declare(yamlcpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp
  GIT_TAG 562aefc114938e388457e6a531ed7b54d9dc1b62 # 0.6.2
)
FetchContent_GetProperties(yamlcpp)
if (NOT yamlcpp_POPULATED)
  FetchContent_Populate(yamlcpp)
  add_subdirectory(${yamlcpp_SOURCE_DIR} ${yamlcpp_BINARY_DIR})
endif()



# ---------------------------------------------------------------------------- #
# Libraries
# ---------------------------------------------------------------------------- #

add_library(world src/world.cpp)
target_include_directories(world PRIVATE include)

add_library(printer src/printer.cpp)
target_include_directories(printer PRIVATE include)
target_link_libraries(printer PUBLIC world)

add_library(reader src/reader.cpp)
target_include_directories(reader PRIVATE include)
target_link_libraries(reader PUBLIC world)

add_library(cellular-automata src/cellular-automata.cpp)
target_include_directories(cellular-automata PRIVATE include)
target_link_libraries(cellular-automata PUBLIC world)

add_library(simulator src/simulator.cpp)
target_include_directories(simulator PRIVATE include)


# ---------------------------------------------------------------------------- #
# Executable
# ---------------------------------------------------------------------------- #

add_executable(${PROJECT_NAME} src/castor.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include
  ${yamlcpp_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC world reader printer
  cellular-automata simulator yaml-cpp)
