#include "SDL2/SDL.h"
#include "game.h"
#include "app_window.h"
#include "load_img.h"
#include "draw.h"

void render() {
	draw_background();
	draw_grid();
	draw_candies(candies);
	finish_rendering();
}


void init_game_entities() {
	int i = 0;
	for (i = 0; i < 9; ++i)
	{
		candies[i].is_pressed = 0;
		candies[i].id = -1;
		candies[i].big_candy_image = big_candies_imgs[i];
		candies[i].small_candy_image = small_candies_imgs[i];
	}
}