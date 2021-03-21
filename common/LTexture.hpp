
#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class LTexture
{

public: 
	// initialize variables
	LTexture();

	// deallocate memory
	~LTexture();

	// load image at path
	bool loadFromFile(std::string, SDL_Renderer* renderer);

	// Deallocates texture
	void free();

	// render texture at coordinate
	void render(int x, int y, SDL_Renderer* renderer);

	// get dimensions
	int getWidth();
	int getHeight();

protected:
	// the acture texture
	SDL_Texture* mTexture;

	// image dimensions
	int mWidth;
	int mHeight;
};