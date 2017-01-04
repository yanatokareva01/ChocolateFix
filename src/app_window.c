#include "app_window.h"

static SDL_Window *screen;

int init_app_window(const char* title, int width, int height) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return -1;
	
	screen = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if ( screen == NULL )
		return -1;
	return 0;	
}
