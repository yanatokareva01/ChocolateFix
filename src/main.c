#include "SDL2/SDL.h"
#include "main.h"
#include "app_window.h"
#include "load_img.h"
#include "levels.h"
#include "game.h"
#include "draw.h"
#include "events.h"

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
	init_game_entities();
	init_drawer();

	state = MENU;
	game_running = 1;
}


static void process_events() {
	static SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		
		switch (event.type) {
			case SDL_QUIT:
				game_running = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					if (state == GAME)
						process_l_mouse_button_in_game(event.button);
					else if (state == MENU)
						process_l_mouse_button_in_menu(event.button);
				}
				break;
		}
	}
}

static void main_loop() {
	while( game_running ) {
		process_events();
		if (state == GAME)
			render_game();
		else if (state == MENU)
			render_menu();
	}
}

static void clean_up() {

}
