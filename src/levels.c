#include <stdio.h>
#include <stdlib.h>

#include "levels.h"

int load_levels( Level_t levels[NUMBER_OF_LEVELS], const char* file ) {
	int i = 0/*,j = 0, k = 0*/;
	FILE* f = fopen(file, "r+b");
	if ( f == NULL ) {
		printf("Can't load levels\n");
		return 1;
	}

	for ( i = 0; i < NUMBER_OF_LEVELS; ++i ) {
		fread(&levels[i].candies_grid, sizeof(int), 9, f);
		
		/*for( k = 0; k < 3; ++k ) {
			for ( j = 0; j < 3; ++j )
				printf("%d ", levels[i].candies_grid[k][j]);
			printf("\n");
		}*/
	}
	fclose(f);	
	return 0;
}

int create_levels( const char* file ) {
	int level4[9] = { 31, 32, 33, 22, 23, 21, 11, 12, 13 };
	int level2[9] = { 23, 33, 32, 31, 13, 12, 11, 22, 21 };
	int level3[9] = { 33, 13, 23, 31, 11, 21, 32, 12, 22 };
	int level5[9] = { 21, 11, 13, 31, 23, 12, 33, 32, 22 };
	int level6[9] = { 12, 11, 21, 13, 33, 31, 23, 32, 22 };
	int level7[9] = { 31, 21, 12, 32, 11, 13, 23, 33, 22 };
	int level8[9] = { 11, 12, 33, 21, 23, 32, 22, 13, 31 };
	int level9[9] = { 31, 22, 13, 33, 21, 12, 32, 23, 11 };
	FILE* f = fopen(file, "w+b");
	
	if ( f == NULL ) {
		printf("Can't create levels\n");
		return 1;
	}

	fwrite(&level2, sizeof(int), 9, f);
	fwrite(&level3, sizeof(int), 9, f);
	fwrite(&level4, sizeof(int), 9, f);
	fwrite(&level5, sizeof(int), 9, f);
	fwrite(&level6, sizeof(int), 9, f);
	fwrite(&level7, sizeof(int), 9, f);
	fwrite(&level8, sizeof(int), 9, f);
	fwrite(&level9, sizeof(int), 9, f);
	fclose(f);
	return 0;
}
