add_executable(
	11_clip_rendering_and_spritesheets.dw
	11_clip_rendering_and_spritesheets.cpp
)

target_link_libraries(11_clip_rendering_and_spritesheets.dw PRIVATE SDL2::SDL2)
target_link_libraries(11_clip_rendering_and_spritesheets.dw PRIVATE SDL2::SDL2_image)
target_link_libraries(11_clip_rendering_and_spritesheets.dw PRIVATE CommonDW)

file(COPY "spritesheet.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")