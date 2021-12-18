/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:16:50 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/18 16:42:41 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, char *path, int	x, int 	y)
{
	int		a;
	int		b;
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path, &a, &b);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void	render_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (j < vars->map_width)
		{
			if (vars->map[i][j] == '1')
				put_image(vars, WALL, j * TILE, i * TILE);
			else
				put_image(vars, GROUND, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}