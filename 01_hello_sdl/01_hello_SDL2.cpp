#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

int main( int argc, char* args[] )
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    // initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Oh no! SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        // create window
        window = SDL_CreateWindow( "SDL2 Tutorial by DW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( window == NULL )
        {
            printf("Oh no! Window was not created! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            screenSurface = SDL_GetWindowSurface( window );
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 100, 255, 100));
            SDL_UpdateWindowSurface( window );

            SDL_Delay(10000);
        }
    }

    SDL_DestroyWindow( window );
    SDL_Quit();
    
    return 0;
}