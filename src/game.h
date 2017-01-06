#ifndef _GAME
#define _GAME
#include "levels.h"

typedef struct {
	SDL_Surface* big_candy_image;
	SDL_Surface* small_candy_image;
	int candy_id;
	int id;
	int is_pressed;
} Candy_t;

Candy_t candies[9];

typedef struct {
	Level_t levels[NUMBER_OF_LEVELS];
	int level;
} Game_t;

void init_game_entities();
void render();
void set_or_reset_candy(int id);
void choose_candy(int candy_id);

#endif
