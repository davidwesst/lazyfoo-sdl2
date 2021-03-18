add_executable(
	07_texture_loading_and_rendering.dw
	07_texture_loading_and_rendering.cpp
)
target_link_libraries(07_texture_loading_and_rendering.dw PRIVATE SDL2::SDL2)
target_link_libraries(07_texture_loading_and_rendering.dw PRIVATE SDL2::SDL2_image)

file(COPY "test_texture.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")