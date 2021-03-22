add_executable(
	12_colour_modulation.dw
	12_colour_modulation.cpp
)

target_link_libraries(12_colour_modulation.dw PRIVATE SDL2::SDL2)
target_link_libraries(12_colour_modulation.dw PRIVATE SDL2::SDL2_image)
target_link_libraries(12_colour_modulation.dw PRIVATE CommonDW)

file(COPY "colour_samples.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")