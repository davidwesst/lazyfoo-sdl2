add_executable(
	06_extension_libs_and_other_image_formats.dw
	06_extension_libs_and_other_image_formats.cpp
)
target_link_libraries(06_extension_libs_and_other_image_formats.dw PRIVATE SDL2::SDL2)
target_link_libraries(06_extension_libs_and_other_image_formats.dw PRIVATE SDL2::SDL2_image)

file(COPY "test_image.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")