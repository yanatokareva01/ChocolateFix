#ifndef _LEVELS
#define _LEVELS

#define NUMBER_OF_LEVELS 8 
	
typedef struct {
	int candies_grid[3][3];
} Level_t;

int load_levels( Level_t levels[NUMBER_OF_LEVELS], const char* file );
int create_levels( const char* file );
#endif 
