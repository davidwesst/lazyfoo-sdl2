#include "LTexture.hpp"

LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = -1;
	mHeight = -1;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
	// remove any preexisting texture
	free();

	// the final texture
	SDL_Texture* newTexture = NULL;

	// load the image
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Oh no! Unable to load the image at %s. SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// set the key
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));

		// create the texture from the surface
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Oh no! Unable to create the texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		// dispose of old surface
		SDL_FreeSurface(loadedSurface);
	}

	// return
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::setColour(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(mTexture, r, g, b);
}

void LTexture::setBlendMode(SDL_BlendMode blendMode)
{
	SDL_SetTextureBlendMode(mTexture, blendMode);
}

void LTexture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::free()
{
	// free it, if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mWidth = -1;
		mHeight = -1;
	}
}

void LTexture::render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(renderer, mTexture, NULL, &renderQuad);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}