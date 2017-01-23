#ifndef _EVENTS
#define _EVENTS

void process_l_mouse_button_in_game(SDL_MouseButtonEvent button);
void process_l_mouse_button_in_menu(SDL_MouseButtonEvent button);
void process_l_mouse_button_in_settings(SDL_MouseButtonEvent button);

int on_candies_set_clicked(Coord_t clicked);
int on_grid_clicked(Coord_t clicked);
int on_ready_button_clicked(Coord_t clicked);
int on_reset_button_clicked(Coord_t clicked);
int on_menu_button_clicked(Coord_t clicked);

int on_start_button_clicked(Coord_t clicked);
int on_settings_button_clicked(Coord_t clicked);
int on_exit_button_clicked(Coord_t clicked);

int on_main_menu_button_clicked(Coord_t clicked);
int on_new_game_button_clicked(Coord_t clicked);
#endif