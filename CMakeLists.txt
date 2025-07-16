cmake_minimum_required(VERSION 3.28)
project(SnakeGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/constants.hpp
        src/node.hpp
        src/doubly_linked_list.hpp
        src/utilities.hpp
        src/random_selector.cpp
        src/snake.cpp
        src/snake.hpp
        src/apple.cpp
        src/apple.hpp
        src/field.cpp
        src/field.hpp
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::System)
