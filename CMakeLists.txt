cmake_minimum_required(VERSION 3.12)
project(elastic_collision-sim C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(elastic_collision_sim ${SOURCES})

target_include_directories(elastic_collision_sim PRIVATE
    include
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(elastic_collision_sim PRIVATE ${SDL2_LIBRARIES})

