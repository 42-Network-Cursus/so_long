/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwastche <cwastche@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:21:52 by cwastche          #+#    #+#             */
/*   Updated: 2022/02/02 23:02:29 by cwastche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static void	put_img(t_data *var, t_asset size, int x, int y, char *sprite)
{
	var->img = mlx_xpm_file_to_image(var->mlx, sprite, &size.h, &size.w);
	mlx_put_image_to_window(var->mlx, var->win, var->img, x, y);
	mlx_destroy_image(var->mlx, var->img);
}

int	generate_map(t_data *var)
{
	t_asset	size;
	int		y;
	int		x;

	y = -1;
	while (var->map[++y])
	{
		x = -1;
		while (var->map[y][++x])
		{
			if (var->map[y][x] == '1')
				put_img(var, size, x * 80, y * 80, WALL);
			else if (var->map[y][x] == 'E')
				put_img(var, size, x * 80, y * 80, EXIT);
			else if (var->map[y][x] == 'C')
				put_img(var, size, x * 80, y * 80, COLLECTIBLE);
			else if (var->map[y][x] == '0')
				put_img(var, size, x * 80, y * 80, FLOOR);
			else if (var->map[y][x] == 'P')
			{
				var->player_x = x;
				var->player_y = y;
				put_img(var, size, x * 80, y * 80, PLAYER);
			}
		}
	}
}
