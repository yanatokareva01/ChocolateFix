#include "SDL2/SDL.h"
#include "main.h"
#include "app_window.h"
#include "load_img.h"
#include "levels.h"
#include "game.h"

/*static int gameRunning = 1;*/
static ProgramState_t state = START;
static Game_t game;

/* Initializes all resources*/
static void resource_init();

/* Initializes all internal entities needed for the game at startup*/
static void game_init();

/* Perfoms a loop, updating and rendering*/
static void main_loop();

/* Frees all resources*/
static void clean_up();

int main(int argc, char** argv) {
	if (argc == 2){  create_levels(ENCODED_LEVELS); return 0; } 
	resource_init();
	game_init();

	main_loop();

	clean_up();

	return 0;
}

static void resource_init() {
	init_app_window(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
	load_imgs();
}

static void game_init() {
	load_levels(game.levels, ENCODED_LEVELS);
	
	state = START;
}

static void main_loop() {

}

static void clean_up() {

}
