#ifndef _DRAW
#define _DRAW

typedef struct {
	int x;
	int y;
} Coord_t;

Coord_t logo_coord;
Coord_t hint_coord;
Coord_t candies_coords_on_grid[9];
Coord_t ready_button_coord;
Coord_t reset_button_coord;
Coord_t menu_button_coord;
Coord_t start_button_coord;
Coord_t exit_button_coord;
Coord_t settings_button_coord;
Coord_t candies_coords[9];

void init_drawer();
void draw_img_with_coord( SDL_Surface* surface, int x, int y );
void draw_img_with_coord_and_offset( SDL_Surface* surface, int x, int y, int x_offset, int y_offset);
void draw_background();
void draw_grid();
void draw_candies(Candy_t candies[9]);
void draw_menu_buttons();
void draw_game_buttons();
void draw_logo();
void draw_hint();
void set_background();
#endif
