/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:16:50 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/23 16:21:17 by tyamcha          ###   ########.fr       */
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

void	place(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		put_image(vars, WALL, j * TILE, i * TILE);
	else if (vars->map[i][j] == 'E')
		put_image(vars, OUT, j * TILE, i * TILE);
	else if (vars->map[i][j] == 'G')
	{
		put_image(vars, GROUND, j * TILE, i * TILE);
		//put_image(vars, GOST, j * TILE, i * TILE);
	}
	else if (vars->map[i][j] == 'C')
	{
		put_image(vars, GROUND, j * TILE, i * TILE);
		put_image(vars, COIN, j * TILE, i * TILE);
	}
	else
		put_image(vars, GROUND, j * TILE, i * TILE);
}

int	render_frame(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (j < vars->map_width)
		{
			place(vars, i, j);
			j++;
		}
		i++;
	}
	put_image(vars, HERO, vars->pl_x * TILE, vars->pl_y * TILE);
	return (0);
}