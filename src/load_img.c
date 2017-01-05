#include "SDL2/SDL.h"
#include "load_img.h"
#include "stdio.h"
#include "SDL2/SDL_image.h"

SDL_Surface *load_img(const char* filename);

SDL_Surface* candies[9];

void load_imgs() {
	load_candies_imgs();
}

void load_candies_imgs() {
	candies[0] = load_img("assets/1.png");
	candies[1] = load_img("assets/2.png");
	candies[2] = load_img("assets/3.png");
	candies[3] = load_img("assets/4.png");
	candies[4] = load_img("assets/5.png");
	candies[5] = load_img("assets/6.png");
	candies[6] = load_img("assets/7.png");
	candies[7] = load_img("assets/8.png");
	candies[8] = load_img("assets/9.png");
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
