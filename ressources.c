#include "../head/so_long.h"

// TO DO
// *Map input checker
//			TO TEST
//		** check .ber file type #OK
//		** 5 symbols (0 1 C E P) #OK
//		** Must have 1 Exit 1 Player 1 Collectible #OK
//		** Walls all around #OK
//		** Rectangle #OK
//		

// *Window // map generator
//		** Handle minimize (clears img atm)
//		** Create window // map W H
//		** push img from map
//		(** next window for bigger maps)
// *HOW TO MOVE PLAYER (Keyhook?)
//		** Player cannot move into wall
//		** Use wasd + arrows for movement
// *Display nbr of moves in terminal


int	create_frame(t_data *var);

int	close_win(t_data *var)
{
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(1);
}

int 	win_error(t_data *var)
{
	printf("Error\n");
	close_win(var);
	return (1);
}

int	key_hook(int keycode, t_data *var)
{
	if (keycode == 65362 || keycode == 119) // UP
	{
			var->y -= 10;
		mlx_clear_window(var->mlx, var->win);
		create_frame(var);
	}
	if (keycode == 65363 || keycode == 100) // RIGHT
	{
		var->x += 10;
		mlx_clear_window(var->mlx, var->win);
		create_frame(var);
	}
	if (keycode == 65364 || keycode == 115) // DOWN
	{
		var->y += 10;
		mlx_clear_window(var->mlx, var->win);
		create_frame(var);
	}
	if (keycode == 65361 || keycode == 97) // LEFT
	{
		//if (var->x > 0)
			var->x -= 10;
		mlx_clear_window(var->mlx, var->win);
		create_frame(var);
	}

	if (keycode == 65307)
		close_win(var);	
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	create_frame(t_data *var)
{
	int x;
	int y;

	x = 0;
	y = 0;

	var->img = mlx_new_image(var->mlx, 100, 100);
	var->addr = mlx_get_data_addr(var->img, &var->bpp, &var->ll, &var->endian);
	while (x < 100)
	{
		y = 0;
		while (y < 100)
		{
			my_mlx_pixel_put(var, x, y, 0x00FFC0CB);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, var->x, var->y);
}

// Use GNL to create map
// Generate window W H depending on map input
// if map > max window size, when touching border change window for rest of map

int main(int ac, char **av)
{
	t_data	var;

	var.x = 0;
	var.y = 0;

	int 	img_h;
	int	img_w;

	// Init with error checks -OK
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (win_error(&var));
	var.img  = mlx_xpm_file_to_image(var.mlx, "img/wall.xpm", &img_h, &img_w);
	var.win = mlx_new_window(var.mlx, 720, 500, "So_long");
	if (var.win == NULL)
		return (win_error(&var));
	
// Creating img -In progress
//	var.img = mlx_new_image(var.mlx, 100, 100);
	var.addr = mlx_get_data_addr(var.img, &var.bpp, &var.ll, &var.endian);
//	my_mlx_pixel_put(&var, 0, 0, 0x00FF0000);
	while (var.x < 1000)
	{
		mlx_put_image_to_window(var.mlx, var.win, var.img, var.x, var.y);
		var.x += 32;
	}

	// Closing with no leaks -OK
//	mlx_loop_hook(var.mlx, create_frame, &var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 0, close_win, &var);
	mlx_loop(var.mlx);


	return (0);
}