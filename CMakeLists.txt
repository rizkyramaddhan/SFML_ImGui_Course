cmake_minimum_required(VERSION 3.10)

project(GameEngine)

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

add_executable(GameEngine src/main.cpp)

target_link_libraries(GameEngine SFML::Graphics SFML::Window SFML::System)