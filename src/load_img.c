#include "SDL2/SDL.h"
#include "load_img.h"
#include "stdio.h"
#include "SDL2/SDL_image.h"

SDL_Surface *load_img(const char* filename);


void load_imgs() {
	load_candies_imgs();
	load_background_imgs();
}

void load_background_imgs() {
	grid = load_img("assets/grid.png");
}

void load_candies_imgs() {
	candies[0] = load_img("assets/11.png");
	candies[1] = load_img("assets/12.png");
	candies[2] = load_img("assets/13.png");
	candies[3] = load_img("assets/21.png");
	candies[4] = load_img("assets/22.png");
	candies[5] = load_img("assets/23.png");
	candies[6] = load_img("assets/31.png");
	candies[7] = load_img("assets/32.png");
	candies[8] = load_img("assets/33.png");
	if (candies[0] == NULL) printf("null((");
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
