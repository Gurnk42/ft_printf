#ifndef GAME_H
# define GAME_H
# include <time.h>
# include <curses.h>
# include <signal.h>
# include "libft.h"

# define WIN_VALUE 2048 //CHECK if %2 == 0
# define BOARD 4

typedef struct	s_env
{
	int	*map;
}		t_env;

#endif
