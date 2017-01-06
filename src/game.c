#include "SDL2/SDL.h"
#include "game.h"
#include "app_window.h"
#include "load_img.h"
#include "draw.h"

void render() {
	draw_background();
	draw_grid();
	draw_candies(candies);
	draw_buttons();
	finish_rendering();
}


void init_game_entities() {
	int i = 0;
	for (i = 0; i < 9; ++i) {
		candies[i].is_pressed = 0;
		candies[i].id = -1;
		candies[i].big_candy_image = big_candies_imgs[i];
		candies[i].small_candy_image = small_candies_imgs[i];
	}

	candies[0].candy_id = 11;
	candies[1].candy_id = 12;
	candies[2].candy_id = 13;
	candies[3].candy_id = 21;
	candies[4].candy_id = 22;
	candies[5].candy_id = 23;
	candies[6].candy_id = 31;
	candies[7].candy_id = 32;
	candies[8].candy_id = 33;
}

void set_or_reset_candy(int id) {
	int i = 0, j = 0;
	for (i = 0; i < 9; ++i) {
		if (candies[i].is_pressed == 1){
			candies[i].is_pressed = 0;

			for (j = 0; j < 9; ++j) {
				if (candies[j].id == id)
					candies[j].id = -1;
			}
				
			candies[i].id = id;
			return;
		}
		if (candies[i].id == id) {
			candies[i].id = -1;
		}
	}
}

void choose_candy(int candy_id) {
	int i = 0;
	for (i = 0; i < 9; ++i) {
		if (candies[i].candy_id == candy_id){
			if (candies[i].is_pressed == 1)
				candies[i].is_pressed = 0;
			else
				candies[i].is_pressed = 1;
		}
		else
			candies[i].is_pressed = 0;
	}
}

Candy_t find_candy_on_grid(int id) {
	int i = 0;
	for (i = 0; i < 9; ++i) {
		if (candies[i].id == id)
			return candies[i];
	}
	return candies[0];
}

void check_answer() {
	int i = 0;
	for (i = 0; i < 9; ++i) {
		Candy_t candy = find_candy_on_grid(i);

		if (candies[i].id == -1 || candy.candy_id != game.levels[game.current_level].candies_grid[i]) {
			/* make message to player*/
			return;
		}
	}
	game.current_level++;
}