add_executable(
	10_colour_keying.dw
	10_colour_keying.cpp
)

target_link_libraries(10_colour_keying.dw PRIVATE SDL2::SDL2)
target_link_libraries(10_colour_keying.dw PRIVATE SDL2::SDL2_image)
target_link_libraries(10_colour_keying.dw PRIVATE CommonDW)

file(COPY "keying_image.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "background_image.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")