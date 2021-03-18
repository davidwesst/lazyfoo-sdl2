cmake_minimum_required( VERSION 3.15 )

project(lazyfoo-sdl2 VERSION 1.0 LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

add_subdirectory(01_hello_sdl)
add_subdirectory(02_getting_an_image_on_screen)
add_subdirectory(03_event_driven_programming)
add_subdirectory(04_key_presses)
add_subdirectory(05_surface_loading_and_soft_stretching)
add_subdirectory(06_extension_libs_and_other_image_formats)
add_subdirectory(07_texture_loading_and_rendering)
add_subdirectory(08_geometry_rendering)
