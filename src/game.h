#ifndef _GAME
#define _GAME
#include "levels.h"

typedef struct {
	Level_t levels[NUMBER_OF_LEVELS];
	int level;
} Game_t;

void init_game();

#endif
