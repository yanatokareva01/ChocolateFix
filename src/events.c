#include "SDL2/SDL.h"
#include "game.h"
#include "draw.h"
#include "events.h"
#include <stdio.h>

void process_l_mouse_button(SDL_MouseButtonEvent button) {
	int id;
	int candy_id;
	Coord_t clicked;
	
	SDL_GetMouseState (&clicked.x, &clicked.y);
	
	id = on_grid_clicked(clicked);
	if (id != -1) {
		set_or_reset_candy(id);
		return;
	}

	candy_id = on_candies_set_clicked(clicked);
	if (candy_id != -1) {
		choose_candy(candy_id);
		return;
	}

}

int on_grid_clicked(Coord_t clicked) {
	int i = 0;
	for (i = 0; i < 9; ++i) {
		if (candies_coords_on_grid[i].x - 3 < clicked.x && candies_coords_on_grid[i].x + 120 > clicked.x)
			if (candies_coords_on_grid[i].y - 3 < clicked.y && candies_coords_on_grid[i].y + 120 > clicked.y){
				return i;
			}
	}
	return -1;
}

int on_candies_set_clicked(Coord_t clicked) {
	int i = 0;
	for (i = 0; i < 9; ++i) {
		if (candies_coords[i].x - 3 < clicked.x && candies_coords[i].x + 90 > clicked.x)
			if (candies_coords[i].y - 3 < clicked.y && candies_coords[i].y + 90 > clicked.y){
				return candies[i].candy_id;
			}
	}
	return -1;
}