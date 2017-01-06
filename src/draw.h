#ifndef _DRAW
#define _DRAW

void draw_img_with_coord( SDL_Surface* surface, int x, int y );
void draw_img_with_coord_and_offset( SDL_Surface* surface, int x, int y, int x_offset, int y_offset);
void draw_background();
void draw_grid();
void set_background();
#endif