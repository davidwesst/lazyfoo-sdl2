add_executable(
	02_getting_an_image_on_screen.dw
	02_getting_an_image_on_screen.cpp
)
target_link_libraries(02_getting_an_image_on_screen.dw PRIVATE SDL2::SDL2)
file(COPY "hello_world.bmp" DESTINATION "${CMAKE_BINARY_DIR}")