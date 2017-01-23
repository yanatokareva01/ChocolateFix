#ifndef _GAME
#define _GAME
#include "levels.h"

typedef struct {
	Level_t levels[NUMBER_OF_LEVELS];
	int current_level;
} Game_t;

Game_t game;

typedef struct {
	SDL_Surface* big_candy_image;
	SDL_Surface* small_candy_image;
	int candy_id;
	int id;
	int is_pressed;
} Candy_t;

Candy_t candies[9];

void init_game_entities();

void set_or_reset_candy(int id);
void choose_candy(int candy_id);
void reset_grid();

void check_answer();
void level_up();

void render_menu();
void render_settings();
void render_game();
void render_game_over();
#endif
