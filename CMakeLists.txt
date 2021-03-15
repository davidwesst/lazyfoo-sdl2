cmake_minimum_required( VERSION 3.15 )

project(lazyfoo-sdl2 VERSION 1.0 LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)

add_subdirectory(01_hello_sdl)
add_subdirectory(02_getting_an_image_on_screen)
add_subdirectory(03_event_driven_programming)
