#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

bool init();
bool loadMedia();
void close();
void DrawGeometry();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

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
            }
        }
    }

    return initSuccess;
}

bool loadMedia()
{
    bool loadMediaSuccess = true;
    return loadMediaSuccess;
}

void DrawGeometry()
{
    // red filled rectangle
    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(gRenderer, &fillRect);

    // outline rectangle
    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3 , SCREEN_HEIGHT * 2 / 3 };
    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(gRenderer, &outlineRect);

    // draw horizontal line
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    // draw vertical yellow dotted line
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 255);
    for (int i = 0; i < SCREEN_HEIGHT; i += 4)
    {
        SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
    }
}

void close()
{
    // destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow( gWindow );
    gRenderer = NULL;
    gWindow = NULL;

    // quit sdl and subsystems
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
                DrawGeometry();

                // update
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    close();
    return 0;
}