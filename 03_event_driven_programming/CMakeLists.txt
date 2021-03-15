add_executable(
	03_event_driven_programming.dw
	03_event_driven_programming.cpp
)
target_link_libraries(03_event_driven_programming.dw PRIVATE SDL2::SDL2)

file(COPY "instructions.bmp" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
