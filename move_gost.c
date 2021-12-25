/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:42:56 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/25 15:09:20 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pos(t_vars *vars, int x, int y, int d1,int d2)
{
	char	tmp;
	
	if (vars->map[x + d1][y + d2] == '0')
	{
		put_image(vars, GROUND, y * TILE, x * TILE);
		vars->map[x][y] = '0';
		vars->map[x + d1][y + d2] = 'G';
	}
}

void	move(t_vars *vars, size_t x, size_t y, size_t px, size_t py)
{
	// printf("-----> %ld %ld\n", x, y);
	// printf("--X    %ld %ld\n", px, py);
	int	rand;
	int	dir;

	rand = ((vars->steps * x - py) / px + vars->coins_collected * py) % 2;
	//printf("RAND %d\n", rand);
	// printf("PX %d PY %d\n", px, py);
	// printf(" X %d  Y %d\n",  x,  y);
	if (rand == 1)
	{
		dir = px - x;
		printf("%d - %d = %d\n", py, y, dir);
		if (dir < 0)
		{
			printf("GO UP\n\n");
			move_pos(vars, x, y, -1, 0);
		}
		else if (dir > 0)
		{
			printf("GO DOWN\n\n");
			move_pos(vars, x, y, 1, 0);
		}
	}
	else
	{
		dir = py - y;
		printf("%d - %d = %d\n", py, y, dir);
		if (dir < 0)
		{
			printf("GO LEFT\n\n");
			move_pos(vars, x, y, 0, -1);
		}
		else if (dir > 0)
		{
			printf("GO RIGHT\n\n");
			move_pos(vars, x, y, 0, 1);
		}
	}
}

void	move_gost(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (j < vars->map_width)
		{
			if (vars->map[i][j] == 'G' && vars->bonus)
			{
				move(vars, i, j, vars->pl_y, vars->pl_x);
				j++;
				i++;
			}
			j++;
		}
		i++;
	}
}