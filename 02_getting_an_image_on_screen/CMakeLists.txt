add_executable(
	02_getting_an_image_on_screen.dw
	02_getting_an_image_on_screen.cpp
)
target_link_libraries(02_getting_an_image_on_screen.dw PRIVATE SDL2::SDL2)

if ( MSVC )
	file(COPY "hello_world.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
else()
	file(COPY "hello_world.bmp" DESTINATION "${CMAKE_BINARY_DIR}")
endif()
