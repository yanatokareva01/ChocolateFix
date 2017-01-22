#ifndef _DRAW
#define _DRAW

typedef struct {
	int x;
	int y;
} Coord_t;

Coord_t hint_coord;
Coord_t candies_coords_on_grid[9];
Coord_t ready_button_coord;
Coord_t reset_button_coord;
Coord_t candies_coords[9];

void init_drawer();
void draw_img_with_coord( SDL_Surface* surface, int x, int y );
void draw_img_with_coord_and_offset( SDL_Surface* surface, int x, int y, int x_offset, int y_offset);
void draw_background();
void draw_grid();
void draw_candies(Candy_t candies[9]);
void draw_buttons();
void draw_hint();
void set_background();
#endif
