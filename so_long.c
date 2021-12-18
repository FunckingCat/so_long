/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:22:02 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/18 19:29:17 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *name, char *desc)
{
	ft_putstr_fd("so_long: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(desc, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	set_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KEYPRESS, 1L << 0, key_press, vars);
	mlx_hook(vars->win, KEYEXIT, 1L << 0, mlx_close, NULL);
	mlx_loop_hook(vars->mlx, render_frame, vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error("invalid args", "usage: ./so_long map.ber");
	read_map(&vars, argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_width * TILE, vars.map_height * TILE, "Hello world!");
	set_hooks(&vars);
	mlx_loop(vars.mlx);
}
