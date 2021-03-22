add_library(
	CommonDW
	STATIC
	"LTexture.cpp"
	"LTexture.hpp"
)

target_link_libraries(CommonDW PRIVATE SDL2::SDL2)
target_link_libraries(CommonDW PRIVATE SDL2::SDL2_image)