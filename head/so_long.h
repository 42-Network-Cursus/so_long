#ifndef SO_LONG_H
# define SO_LONG_H

#include <X11/Xlib.h>
#include <X11/keysymdef.h>

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define WALL "img/xpm/wall.xpm"
#define	CHAR "img/xpm/char.xpm"
#define COLLECTIBLE "img/xpm/collectible.xpm"
#define COLLECTED "img/xpm/collected.xpm"
#define EXIT "img/xpm/exit.xpm"
#define FLOOR "img/xpm/floor.xpm"

#define HEIGHT 1080
#define WIDTH 1920

typedef struct	s_data 
{
	void	*mlx;
	void	*win;
	void	*img;

	char	**map;
	int		player_x;
	int		player_y;

	int	p; // player
	int	c; // collectible
	int	e; // exit
}				t_data;

/*
typedef struct	s_asset
{
	int h; // height
	int w; // width
}				t_asset;
*/

// Src
void    map_check(t_data *var);
char    *map_read(char *map_path);
int		generate_map(t_data *var);

// Utils
void    error(char	*msg, t_data *var);
void	map_free(char **map);

#endif
