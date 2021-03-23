add_executable(
	13_alpha_blending.dw
	13_alpha_blending.cpp
)

target_link_libraries(13_alpha_blending.dw PRIVATE SDL2::SDL2)
target_link_libraries(13_alpha_blending.dw PRIVATE SDL2::SDL2_image)
target_link_libraries(13_alpha_blending.dw PRIVATE CommonDW)

file(COPY "background_image.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "modulated_image.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")