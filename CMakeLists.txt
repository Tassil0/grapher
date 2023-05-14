cmake_minimum_required(VERSION 3.14)
project(
        grapher
        VERSION 0.1
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info

include(cmake/CPM.cmake)

file(GLOB SOURCES src/*.cpp src/*.h src/*/*.cpp src/*/*.h)

add_executable(${CMAKE_PROJECT_NAME}.out ${SOURCES})