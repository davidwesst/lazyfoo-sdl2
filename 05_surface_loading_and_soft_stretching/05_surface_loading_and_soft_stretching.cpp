#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string path);

SDL_Window* gWindow = NULL;
SDL_Surface* gWindowSurface = NULL;
SDL_Surface* gSurface = NULL;


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
            gWindowSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return initSuccess;
}

SDL_Surface* loadSurface(std::string path)
{
    // the final optimized image
    SDL_Surface* optimizedSurface = NULL;

    // load the image
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

    if (loadedSurface == NULL)
    {
        printf("Oh no! The image %s failed to load. SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
        // convert image to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gWindowSurface->format, 0);
        if (optimizedSurface == NULL)
        {
            printf("Oh no! Unable to optimize the image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // free the loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

bool loadMedia()
{
    bool loadMediaSuccess = true;

    gSurface = loadSurface("stretch_me.bmp");

    return loadMediaSuccess;
}

void close()
{
    // destroy surface
    SDL_FreeSurface(gSurface);
    gSurface = NULL;

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

                // stretch and set the surface
                SDL_Rect stretchRect;
                stretchRect.x = 0;
                stretchRect.y = 0;
                stretchRect.w = SCREEN_WIDTH;
                stretchRect.h = SCREEN_HEIGHT;
                SDL_BlitScaled(gSurface, NULL, gWindowSurface, &stretchRect);

                // update
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }

    close();
    return 0;
}