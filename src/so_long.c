#include "../head/so_long.h"

static int	close_win(t_data *var)
{
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	map_free(var->map);
	exit(1);
}

static int 	error_win(t_data *var, int n)
{
	close_win(var);
	printf("Error.\n");
	if (n == 1)
		printf("Mlx initialization failed.\n");
	if (n == 2)
		printf("Window initialization failed.\n");
	return (1);
}

int	move_up(t_data *var)
{
	int		x;
	int		y;
	char	tmp;

	if (var->map[var->player_y - 1][var->player_x] == '0')
	{
		x = var->player_x;
		y = var->player_y;
		tmp = var->map[y][x];
		var->map[y][x] = var->map[y - 1][x];
		var->map[y - 1][x] = tmp;
	}
	generate_map(var);
}

int	move_down(t_data *var)
{
	int		x;
	int		y;
	char	tmp;

	if (var->map[var->player_y + 1][var->player_x] == '0')
	{
		x = var->player_x;
		y = var->player_y;
		tmp = var->map[y][x];
		var->map[y][x] = var->map[y + 1][x];
		var->map[y + 1][x] = tmp;
	}
	generate_map(var);
}

int	move_left(t_data *var)
{
	int		x;
	int		y;
	char	tmp;

	if (var->map[var->player_y][var->player_x - 1] == '0')
	{
		x = var->player_x;
		y = var->player_y;
		tmp = var->map[y][x];
		var->map[y][x] = var->map[y][x - 1];
		var->map[y][x - 1] = tmp;
	}
	generate_map(var);
}

int	move_right(t_data *var)
{
	int		x;
	int		y;
	char	tmp;
	if (var->map[var->player_y][var->player_x + 1] == '0')
	{
		x = var->player_x;
		y = var->player_y;
		tmp = var->map[y][x];
		var->map[y][x] = var->map[y][x + 1];
		var->map[y][x + 1] = tmp;
	}
	generate_map(var);
}

static int	key_hook(int keycode, t_data *var)
{
	if (keycode == 65362 || keycode == 119) // UP
		move_up(var);
	else if (keycode == 65363 || keycode == 100) // RIGHT
		move_right(var);
	else if (keycode == 65364 || keycode == 115) // DOWN
		move_down(var);
	else if (keycode == 65361 || keycode == 97) // LEFT
		move_left(var);
	else if (keycode == 65307)
		close_win(var);	
}

int main(int ac, char **av)
{
	char	*line;

	t_data	var;
	//t_asset wall;

	line = map_read(av[1]);
	var.map = ft_split(line, '\n');
	free(line);
	map_check(&var);

	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (error_win(&var, 1));
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "Cwastche's So_long Project");
	if (var.win == NULL)
		return (error_win(&var, 2));

	generate_map(&var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 0, close_win, &var);
	//mlx_loop_hook(var.mlx, generate_map, &var);
	mlx_loop(var.mlx);

	map_free(var.map);
	
	return (0);
}
