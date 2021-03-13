#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

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
            gSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return initSuccess;
}

bool loadMedia()
{
    bool loadMediaSuccess = true;

    gHelloWorld = SDL_LoadBMP( "hello_world.bmp" );
    if(gHelloWorld == NULL)
    {
        printf( "Oh no! The image failed to load. SDL Error: %s\n", SDL_GetError() );
        loadMediaSuccess = false;
    }

    return loadMediaSuccess;
}

void close()
{
    // deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    // destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    // quit sdl
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
            // apply the image to the window surface
            SDL_BlitSurface( gHelloWorld, NULL, gSurface, NULL );

            // update and wait
            SDL_UpdateWindowSurface( gWindow );
            SDL_Delay(2000);
        }
    }

    close();
    return 0;
}