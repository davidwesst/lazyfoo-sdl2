add_executable(
	09_the_viewport.dw
	09_the_viewport.cpp
)
target_link_libraries(09_the_viewport.dw PRIVATE SDL2::SDL2)
target_link_libraries(09_the_viewport.dw PRIVATE SDL2::SDL2_image)

file(COPY "viewport_image.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")