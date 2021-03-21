add_library(
	libCommonDW
	STATIC
	"LTexture.cpp"
	"LTexture.hpp"
)

target_link_libraries(libCommonDW PRIVATE SDL2::SDL2)
target_link_libraries(libCommonDW PRIVATE SDL2::SDL2_image)