/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:01:09 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/25 11:51:59 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_collected(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	put_image(vars, GROUND, y * TILE, x * TILE);
	vars->coins_collected++;
}

void	ft_move(t_vars *vars, int	x, int y)
{
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == '1')
		return ;
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == 'C')
		coin_collected(vars, vars->pl_y + y, vars->pl_x + x);
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == 'G' && vars->bonus)
	{
		printf("YOU LOST\n");
		mlx_close();
	}
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == 'E')
	{
		if (vars->coins_collected == vars->coins)
		{
			printf("!!! YOU WON !!!\n");
			mlx_close();
		}
		else
			return ;
	}
	printf("%d\n", vars->steps++);
	put_image(vars, GROUND, vars->pl_x * TILE, vars->pl_y * TILE);
	vars->pl_x += x;
	vars->pl_y += y;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == A_KEY)
		ft_move(vars, -1, 0);
	if (keycode == D_KEY)
		ft_move(vars, 1, 0);
	if (keycode == S_KEY)
		ft_move(vars, 0, 1);
	if (keycode == W_KEY)
		ft_move(vars, 0, -1);
	if (keycode == ESC)
		mlx_close();
	return (0);
}

int	mlx_close()
{
	exit (EXIT_SUCCESS);
}