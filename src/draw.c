#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "game.h"
#include "draw.h"
#include "load_img.h"
#include "app_window.h"

Coord_t grid_coord;

void init_drawer() {
	grid_coord.x = 425;
	grid_coord.y = 65;

	hint_coord.x = 20;
	hint_coord.y = 65;

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

	candies_coords_on_grid[0].x = 460;
	candies_coords_on_grid[0].y = 88; 
	candies_coords_on_grid[1].x = 594;
	candies_coords_on_grid[1].y = 88;
	candies_coords_on_grid[2].x = 727;
	candies_coords_on_grid[2].y = 88;
	candies_coords_on_grid[3].x = 460;
	candies_coords_on_grid[3].y = 219;
	candies_coords_on_grid[4].x = 594;
	candies_coords_on_grid[4].y = 219;
	candies_coords_on_grid[5].x = 727;
	candies_coords_on_grid[5].y = 219;
	candies_coords_on_grid[6].x = 460;
	candies_coords_on_grid[6].y = 352;
	candies_coords_on_grid[7].x = 594;
	candies_coords_on_grid[7].y = 352;
	candies_coords_on_grid[8].x = 727;
	candies_coords_on_grid[8].y = 352;

	ready_button_coord.x = 223;
	ready_button_coord.y = 515;
	reset_button_coord.x = 20;
	reset_button_coord.y = 515;
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
		if (candies[i].id == -1){
			if (candies[i].is_pressed == 0)
				draw_img_with_coord(candies[i].small_candy_image, candies_coords[i].x, candies_coords[i].y);
		}
		else {
			draw_img_with_coord(candies[i].big_candy_image, candies_coords_on_grid[candies[i].id].x , candies_coords_on_grid[candies[i].id].y);
		}
	}
}

void draw_buttons() {
	draw_img_with_coord(ready_button, ready_button_coord.x, ready_button_coord.y);
	draw_img_with_coord(reset_button, reset_button_coord.x, reset_button_coord.y);
}

void draw_hint() {
	draw_img_with_coord(hint_images[game.current_level], hint_coord.x, hint_coord.y);
}