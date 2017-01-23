#include "app_window.h"

static SDL_Window* window;
static SDL_Surface* screen;

int init_app_window(const char* title, int width, int height) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return -1;
	
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		fputs("Can't create window", stderr);
		return 1;
	}
	screen = SDL_GetWindowSurface( window );
	
	return 0;	
}

void set_surface( int x, int y, SDL_Surface* surface ) {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;

	SDL_BlitSurface(surface, NULL, screen, &dest);
}

void set_background() {
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 206, 84));
}

void finish_rendering() {
	SDL_UpdateWindowSurface(window);
}