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

	if (on_button_clicked(clicked, ready_button_coord, 182, 93) == 1) {
		check_answer();
		return;
	}
	
	if (on_button_clicked(clicked, reset_button_coord, 182, 93) == 1) {
		reset_grid();
		return;
	}

	if (on_button_clicked(clicked, menu_button_coord, 93, 45) == 1) {
		state = MENU;
		return;
	}
}

void process_l_mouse_button_in_menu(SDL_MouseButtonEvent button) {
	Coord_t clicked;
	
	SDL_GetMouseState (&clicked.x, &clicked.y);

	if (on_button_clicked(clicked, start_button_coord, 182, 93) == 1) {
		state = GAME;
		return;
	}

	if (on_button_clicked(clicked, settings_button_coord, 182, 93) == 1) {
		state = SETTINGS;
		return;
	}

	if (on_button_clicked(clicked, exit_button_coord, 182, 93) == 1) {
		game_running = 0;
		return;
	}
}

void process_l_mouse_button_in_settings(SDL_MouseButtonEvent button) {
	Coord_t clicked;
	
	SDL_GetMouseState (&clicked.x, &clicked.y);

	if (on_button_clicked(clicked, main_menu_button_coord, 182, 93) == 1) {
		state = MENU;
		return;
	}

	if (on_button_clicked(clicked, new_game_button_coord, 182, 93) == 1) {
		game.current_level = 0;
		state = GAME;
		return;
	}	
	
	SDL_GetMouseState (&clicked.x, &clicked.y);
}

void process_l_mouse_button_in_game_over(SDL_MouseButtonEvent button) {
	Coord_t clicked;

	SDL_GetMouseState(&clicked.x, &clicked.y);

	if (on_button_clicked(clicked, exit_button_coord, 182, 93)) {
		game.current_level = 0;
		game_running = 0;
		return;
	}

	if (on_button_clicked(clicked, new_game_button_coord, 182, 93)) {
		game.current_level = 0;
		state = GAME;
		return;
	}

	if (on_button_clicked(clicked, main_menu_button_coord, 182, 93)) {
		game.current_level = 0;
		state = MENU;
		return;
	}
}

int on_button_clicked(Coord_t clicked_coord, Coord_t button_coord, int width, int height) {
	if (button_coord.x < clicked_coord.x && button_coord.x + width > clicked_coord.x) {
		if (button_coord.y < clicked_coord.y && button_coord.y + height > clicked_coord.y) {
			return 1;
		}
	}
	return 0;
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