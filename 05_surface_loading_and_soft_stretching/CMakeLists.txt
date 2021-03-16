add_executable(
	05_surface_loading_and_soft_stretching.dw
	05_surface_loading_and_soft_stretching.cpp
)
target_link_libraries(05_surface_loading_and_soft_stretching.dw PRIVATE SDL2::SDL2)

file(COPY "stretch_me.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

