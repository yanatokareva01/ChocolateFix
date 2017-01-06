#ifndef _DRAW
#define _DRAW

void init_drawer();
void draw_img_with_coord( SDL_Surface* surface, int x, int y );
void draw_img_with_coord_and_offset( SDL_Surface* surface, int x, int y, int x_offset, int y_offset);
void draw_background();
void draw_grid();
void draw_candies(Candy_t candies[9]);
void set_background();
#endif
