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

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Rect gSpriteClips[4];

LTexture gSpriteSheetTexture;

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

bool loadMedia()
{
    bool loadMediaSuccess = true;

    // load spritesheet
    if (gSpriteSheetTexture.loadFromFile("spritesheet.png", gRenderer) == false)
    {
        printf("Failed to spritesheet texture. \n");
        loadMediaSuccess = false;
    }

    // top left sprite
    gSpriteClips[0].x = 0;
    gSpriteClips[0].y = 0;
    gSpriteClips[0].w = 32;
    gSpriteClips[0].h = 32;

    // top right sprite
    gSpriteClips[1].x = 32;
    gSpriteClips[1].y = 0;
    gSpriteClips[1].w = 32;
    gSpriteClips[1].h = 32;

    // bottom left sprite
    gSpriteClips[2].x = 0;
    gSpriteClips[2].y = 32;
    gSpriteClips[2].w = 32;
    gSpriteClips[2].h = 32;

    // bottom right sprite
    gSpriteClips[3].x = 32;
    gSpriteClips[3].y = 32;
    gSpriteClips[3].w = 32;
    gSpriteClips[3].h = 32;

    return loadMediaSuccess;
}

void close()
{
    // destroy texture
    gSpriteSheetTexture.free();

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
                gSpriteSheetTexture.render(0, 0, gRenderer, &gSpriteClips[0]);
                gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[1].w, 0, gRenderer, &gSpriteClips[1]);
                gSpriteSheetTexture.render(0, SCREEN_HEIGHT - gSpriteClips[2].h, gRenderer, &gSpriteClips[2]);
                gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[3].w, SCREEN_HEIGHT - gSpriteClips[3].h, gRenderer, &gSpriteClips[3]);

                // update
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    close();
    return 0;
}