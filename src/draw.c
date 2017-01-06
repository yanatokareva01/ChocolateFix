#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "draw.h"
#include "load_img.h"
#include "app_window.h"

void draw_background() {
	set_background();
}

void draw_grid() {
	draw_img_with_coord(grid, 425, 65);
}

void draw_img_with_coord( SDL_Surface* surface, int x, int y ) {
	draw_img_with_coord_and_offset( surface, x, y, 0, 0 );
}

void draw_img_with_coord_and_offset( SDL_Surface* surface, int x, int y, int x_offset, int y_offset ) {
	set_surface( x + x_offset, y + y_offset, surface);
}