/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche <cwastche@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:21:52 by cwastche          #+#    #+#             */
/*   Updated: 2022/01/30 22:22:38 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static void	put_wall(t_data *var, t_asset size, int x, int y)
{
	var->img = mlx_xpm_file_to_image(var->mlx, WALL, &size.h, &size.w);
	mlx_put_image_to_window(var->mlx, var->win, var->img, x, y);
	mlx_destroy_image(var->mlx, var->img);
}

static void	put_player(t_data *var, t_asset size, int x, int y)
{
	var->img = mlx_xpm_file_to_image(var->mlx, PLAYER, &size.h, &size.w);
	mlx_put_image_to_window(var->mlx, var->win, var->img, x, y);
	mlx_destroy_image(var->mlx, var->img);
}

static void	put_exit(t_data *var, t_asset size, int x, int y)
{
	var->img = mlx_xpm_file_to_image(var->mlx, EXIT, &size.h, &size.w);
	mlx_put_image_to_window(var->mlx, var->win, var->img, x, y);
	mlx_destroy_image(var->mlx, var->img);
}

static void	put_collectible(t_data *var, t_asset size, int x, int y)
{
	var->img = mlx_xpm_file_to_image(var->mlx, COLLECTIBLE, &size.h, &size.w);
	mlx_put_image_to_window(var->mlx, var->win, var->img, x, y);
	mlx_destroy_image(var->mlx, var->img);
}

int	generate_map(t_data *var)
{
	t_asset	size;
	int		y;
	int		x;

	mlx_clear_window(var->mlx, var->win);
	y = -1;
	while (var->map[++y])
	{
		x = -1;
		while (var->map[y][++x])
		{
			if (var->map[y][x] == '1')
				put_wall(var, size, x * 80, y * 80);
			else if (var->map[y][x] == 'E')
				put_exit(var, size, x * 80, y * 80);
			else if (var->map[y][x] == 'C')
				put_collectible(var, size, x * 80, y * 80);
			else if (var->map[y][x] == 'P')
			{
				var->player_x = x;
				var->player_y = y;
				put_player(var, size, x * 80, y * 80);
			}
		}
	}
}
