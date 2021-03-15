add_executable(01_hello_sdl.dw ../01_hello_sdl/01_hello_SDL2.cpp)
target_link_libraries(01_hello_sdl.dw PRIVATE SDL2::SDL2)