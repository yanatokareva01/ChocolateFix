#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "game.h"
#include "draw.h"
#include "load_img.h"
#include "app_window.h"


typedef struct {
	int x;
	int y;
} Coord_t;

Coord_t candies_coords[9];
Coord_t grid_coord;

void init_drawer() {
	grid_coord.x = 425;
	grid_coord.y = 65;
	candies_coords[0].x = 434;
	candies_coords[0].y = 515; 
	candies_coords[1].x = 547;
	candies_coords[1].y = 515;
	candies_coords[2].x = 660;
	candies_coords[2].y = 515;
	candies_coords[3].x = 773;
	candies_coords[3].y = 515;
	candies_coords[4].x = 886;
	candies_coords[4].y = 515;
	candies_coords[5].x = 890;
	candies_coords[5].y = 75;
	candies_coords[6].x = 890;
	candies_coords[6].y = 188;
	candies_coords[7].x = 890;
	candies_coords[7].y = 301;
	candies_coords[8].x = 890;
	candies_coords[8].y = 414;
}

void draw_background() {
	set_background();
}

void draw_grid() {
	draw_img_with_coord(grid, grid_coord.x, grid_coord.y);
}

void draw_img_with_coord( SDL_Surface* surface, int x, int y ) {
	draw_img_with_coord_and_offset( surface, x, y, 0, 0 );
}

void draw_img_with_coord_and_offset( SDL_Surface* surface, int x, int y, int x_offset, int y_offset ) {
	set_surface( x + x_offset, y + y_offset, surface);
}

void draw_candies (Candy_t candies[9]) {
	int i = 0;
	for (i = 0; i < 9; ++i) {
		if (candies[i].x == -1 && candies[i].y == -1)
			draw_img_with_coord(candies[i].small_candy_image, candies_coords[i].x, candies_coords[i].y);
	}
}