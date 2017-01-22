#ifndef _MAIN
#define _MAIN

#define SCREEN_TITLE "Chocolate Fix"
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 650
#define ENCODED_LEVELS "resources/levels"

typedef enum {
	START,
	MENU,
	GAME
} ProgramState_t;

ProgramState_t state;
int game_running;
#endif   
