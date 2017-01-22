#ifndef _LOAD_IMG
#define _LOAD_IMG

SDL_Surface* big_candies_imgs[9];
SDL_Surface* small_candies_imgs[9];
SDL_Surface* ready_button;
SDL_Surface* reset_button;
SDL_Surface* background;
SDL_Surface* grid;
SDL_Surface* hint_images[5];

void load_imgs();
void load_buttons_imgs();
void load_candies_imgs();
void load_background_imgs();
void load_buttons_imgs();
void load_hint_imgs();

#endif
