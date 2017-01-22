#include "SDL2/SDL.h"
#include "load_img.h"
#include "stdio.h"
#include "SDL2/SDL_image.h"

SDL_Surface *load_img(const char* filename);


void load_imgs() {
	load_candies_imgs();
	load_background_imgs();
	load_buttons_imgs();
	load_hint_imgs();
}

void load_background_imgs() {
	grid = load_img("assets/grid.png");
}

void load_candies_imgs() {
	big_candies_imgs[0] = load_img("assets/11big.png");
	big_candies_imgs[1] = load_img("assets/12big.png");
	big_candies_imgs[2] = load_img("assets/13big.png");
	big_candies_imgs[3] = load_img("assets/21big.png");
	big_candies_imgs[4] = load_img("assets/22big.png");
	big_candies_imgs[5] = load_img("assets/23big.png");
	big_candies_imgs[6] = load_img("assets/31big.png");
	big_candies_imgs[7] = load_img("assets/32big.png");
	big_candies_imgs[8] = load_img("assets/33big.png");
	
	small_candies_imgs[0] = load_img("assets/11small.png");
	small_candies_imgs[1] = load_img("assets/12small.png");
	small_candies_imgs[2] = load_img("assets/13small.png");
	small_candies_imgs[3] = load_img("assets/21small.png");
	small_candies_imgs[4] = load_img("assets/22small.png");
	small_candies_imgs[5] = load_img("assets/23small.png");
	small_candies_imgs[6] = load_img("assets/31small.png");
	small_candies_imgs[7] = load_img("assets/32small.png");
	small_candies_imgs[8] = load_img("assets/33small.png");
}

void load_buttons_imgs() {
	ready_button = load_img("assets/ready_button.png");
	reset_button = load_img("assets/reset_button.png");
}

SDL_Surface* load_img( const char* filename ) {
	/*The img that's loaded*/
	SDL_Surface* loadedImage;
	
	/*Initialize PNG loading*/
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return NULL;
	}	

	/*Load the img using SDL_image*/
	loadedImage = IMG_Load(filename);

	printf("loading img: %s\n", filename);		

	/*If the image loaded*/
	if( loadedImage == NULL ) {
		printf("Error opening image %s\n", filename);
	}

	/*Return the optimized image*/
	return loadedImage;
}


void load_hint_imgs() {
	hint_images[0] = load_img("assets/level1.png");
	hint_images[1] = load_img("assets/level2.png");
	hint_images[2] = load_img("assets/level3.png");
	hint_images[3] = load_img("assets/level4.png");
	hint_images[4] = load_img("assets/level5.png");
}