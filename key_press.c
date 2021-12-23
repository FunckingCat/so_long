/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:01:09 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/23 16:45:00 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_collected(t_vars *vars, int x, int y)
{
	vars->map[x][y] = '0';
	vars->coins_collected++;
}

void	ft_move(t_vars *vars, int	x, int y)
{
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == '1')
		return ;
	if (vars->map[vars->pl_y + y][vars->pl_x + x] == 'C')
		coin_collected(vars, vars->pl_y + y, vars->pl_x + x);
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
	vars->pl_x += x;
	vars->pl_y += y;
	render_frame(vars);
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