#include "SDL2/SDL.h"
#include "game.h"
#include "draw.h"
#include "main.h"
#include "events.h"
#include <stdio.h>

void process_l_mouse_button_in_game(SDL_MouseButtonEvent button) {
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

	if (on_ready_button_clicked(clicked) == 1) {
		check_answer();
		return;
	}
	
	if (on_reset_button_clicked(clicked) == 1) {
		reset_grid();
		return;
	}

	if (on_menu_button_clicked(clicked) == 1) {
		state = MENU;
		return;
	}
}

void process_l_mouse_button_in_menu(SDL_MouseButtonEvent button) {
	Coord_t clicked;
	
	SDL_GetMouseState (&clicked.x, &clicked.y);

	if (on_start_button_clicked(clicked) == 1) {
		state = GAME;
		return;
	}

	if (on_settings_button_clicked(clicked) == 1) {
		printf("on settings clicked\n");
		return;
	}

	if (on_exit_button_clicked(clicked) == 1) {
		game_running = 0;
		return;
	}
}

int on_menu_button_clicked(Coord_t clicked) {
	if (menu_button_coord.x < clicked.x && menu_button_coord.x + 93 > clicked.x) {
		if (menu_button_coord.y < clicked.y && menu_button_coord.y + 45 > clicked.y) {
			return 1;
		}
	}
	return -1;	
}

int on_start_button_clicked(Coord_t clicked) {
	if (start_button_coord.x < clicked.x && start_button_coord.x + 182 > clicked.x) {
		if (start_button_coord.y < clicked.y && start_button_coord.y + 93 > clicked.y) {
			return 1;
		}
	}
	return -1;	
}

int on_settings_button_clicked(Coord_t clicked) {
	if (settings_button_coord.x < clicked.x && settings_button_coord.x + 182 > clicked.x) {
		if (settings_button_coord.y < clicked.y && settings_button_coord.y + 93 > clicked.y) {
			return 1;
		}
	}
	return -1;	
}


int on_exit_button_clicked(Coord_t clicked) {
	if (exit_button_coord.x < clicked.x && exit_button_coord.x + 182 > clicked.x) {
		if (exit_button_coord.y < clicked.y && exit_button_coord.y + 93 > clicked.y) {
			return 1;
		}
	}
	return -1;	
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

int on_ready_button_clicked(Coord_t clicked) {
	if (ready_button_coord.x < clicked.x && ready_button_coord.x + 182 > clicked.x) {
		if (ready_button_coord.y < clicked.y && ready_button_coord.y + 93 > clicked.y) {
			return 1;
		}
	}
	return -1;
}

int on_reset_button_clicked(Coord_t clicked) {
	if (reset_button_coord.x < clicked.x && reset_button_coord.x + 182 > clicked.x) {
		if (reset_button_coord.y < clicked.y && reset_button_coord.y + 93 > clicked.y) {
			return 1;
		}
	}
	return -1;
}