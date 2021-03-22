#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

#include "../common/LTexture.hpp"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture(std::string);

void RenderToTopLeftViewport();
void RenderToTopRightViewport();
void RenderToBottomHalfViewport();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gPlayerTexture;
LTexture gBackgroundTexture;


bool init()
{
    bool initSuccess = true;

    // initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Oh no! SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        // create window
        gWindow = SDL_CreateWindow( "SDL2 Tutorial by DW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( gWindow == NULL )
        {
            printf("Oh no! Window was not created! SDL Error: %s\n", SDL_GetError() );
            initSuccess = false;
        }
        else
        {
            // create renderer
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if ( gRenderer == NULL ) 
            {
                printf("Oh no! SDL_Renderer could not initialize! SDL Error: %s\n", SDL_GetError());
                initSuccess = false;
            }
            else
            {
                // initialize renderer colour
                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

                // initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    initSuccess = false;
                }
            }
        }
    }

    return initSuccess;
}

SDL_Texture* loadTexture(std::string path)
{
    // the final optimized imagegimp
    SDL_Texture* newTexture = NULL;

    // load the image
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == NULL)
    {
        printf("Oh no! The image %s failed to load. SDL Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // create texture from surface
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Oh no! Unable to load the texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // free the loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

bool loadMedia()
{
    bool loadMediaSuccess = true;

    // load player
    if (gPlayerTexture.loadFromFile("keying_image.png", gRenderer) == false)
    {
        printf("Failed to load player texture. \n");
        loadMediaSuccess = false;
    }

    // load background
    if (gBackgroundTexture.loadFromFile("background_image.png", gRenderer) == false)
    {
        printf("Failed to load background texture. \n");
        loadMediaSuccess = false;
    }

    return loadMediaSuccess;
}

void close()
{
    // destroy texture
    gPlayerTexture.free();
    gBackgroundTexture.free();

    // destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow( gWindow );
    gRenderer = NULL;
    gWindow = NULL;

    // quit sdl and subsystems
    IMG_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    if( init() == false )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        // load media file
        if( loadMedia() == false )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            // declare quitting variables
            bool quit = false;
            SDL_Event e;

            // start main loop
            while (!quit)
            {
                // event loop for handling events
                while (SDL_PollEvent(&e) != 0)
                {
                    // check if user requests quit event
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }

                // clear screen
                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
                SDL_RenderClear(gRenderer);

                // draw
                gBackgroundTexture.render(0, 0, gRenderer);
                gPlayerTexture.render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, gRenderer);

                // update
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    close();
    return 0;
}