add_executable(
	04_key_presses.dw
	04_key_presses.cpp
)
target_link_libraries(04_key_presses.dw PRIVATE SDL2::SDL2)

file(COPY "default.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "up.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "down.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "left.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "right.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
