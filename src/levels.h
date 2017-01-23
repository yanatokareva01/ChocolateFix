#ifndef _LEVELS
#define _LEVELS

#define NUMBER_OF_LEVELS 10
	
typedef struct {
	int candies_grid[9];
} Level_t;

int create_levels	( const char* file );
int load_levels		( const char* file );
int save_state		( const char* file );
int load_state		( const char* state_file );
#endif 
