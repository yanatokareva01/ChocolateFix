#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "game.h"
#include "draw.h"
#include "load_img.h"
#include "app_window.h"

Coord_t grid_coord;

void init_drawer() {
	logo_coord.x = 320;
	logo_coord.y = 30;

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
	menu_button_coord.x = 890;
	menu_button_coord.y = 10;
	
	start_button_coord.x = 400;
	start_button_coord.y = 290;
	settings_button_coord.x = 400;
	settings_button_coord.y = 408;
	exit_button_coord.x = 400;
	exit_button_coord.y = 526;

	new_game_button_coord.x = 400;
	new_game_button_coord.y = 290;
	main_menu_button_coord.x = 400;
	main_menu_button_coord.y = 408;
}

void draw_background() {
	set_background();
}

void draw_grid() {
	draw_img_with_coord(grid, grid_coord.x, grid_coord.y);
}

void draw_img_with_coord( SDL_Surface* surface, int x, int y ) {
	set_surface( x, y, surface);
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

void draw_game_buttons() {
	draw_img_with_coord(ready_button, ready_button_coord.x, ready_button_coord.y);
	draw_img_with_coord(reset_button, reset_button_coord.x, reset_button_coord.y);
	draw_img_with_coord(menu_button, menu_button_coord.x, menu_button_coord.y);
}

void draw_menu_buttons() {
	draw_img_with_coord(start_button, start_button_coord.x, start_button_coord.y);
	draw_img_with_coord(settings_button, settings_button_coord.x, settings_button_coord.y);
	draw_img_with_coord(exit_button, exit_button_coord.x, exit_button_coord.y);
}

void draw_settings_buttons() {
	draw_img_with_coord(main_menu_button, main_menu_button_coord.x, main_menu_button_coord.y);
	draw_img_with_coord(new_game_button, new_game_button_coord.x, new_game_button_coord.y);
}

void draw_game_over_buttons() {
	draw_img_with_coord(main_menu_button, main_menu_button_coord.x, main_menu_button_coord.y);
	draw_img_with_coord(new_game_button, new_game_button_coord.x, new_game_button_coord.y);	
	draw_img_with_coord(exit_button, exit_button_coord.x, exit_button_coord.y);
}

void draw_hint() {
	draw_img_with_coord(hint_images[game.current_level], hint_coord.x, hint_coord.y);
}

void draw_logo() {
	draw_img_with_coord(logo, logo_coord.x, logo_coord.y);	
}