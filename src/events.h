#ifndef _EVENTS
#define _EVENTS

int on_candies_set_clicked(Coord_t clicked);
int on_grid_clicked(Coord_t clicked);
int on_ready_button_clicked(Coord_t clicked);
int on_reset_button_clicked(Coord_t clicked);
void process_l_mouse_button(SDL_MouseButtonEvent button);
#endif