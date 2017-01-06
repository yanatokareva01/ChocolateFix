#ifndef _APP_WINDOW
#define _APP_WINDOW
#include "SDL2/SDL.h"

void finish_rendering();
int init_app_window( const char* title, int width, int height );
void set_surface( int x, int y, SDL_Surface* surface ); 
#endif