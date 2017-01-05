#include "SDL2/SDL.h"
#include "main.h"
#include "app_window.h"
#include "load_img.h"
/* Initializes all resources*/
static void resource_init();

/* Initializes all internal entities needed for the game at startup*/
static void game_init();

/* Perfoms a loop, updating and rendering*/
static void main_loop();

/* Frees all resources*/
static void clean_up();

int main() {
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

}

static void main_loop() {

}

static void clean_up() {

}
