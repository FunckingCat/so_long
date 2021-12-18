/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:22:02 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/18 18:08:40 by tyamcha          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		error("invalid args", "usage: ./so_long map.ber");
	read_map(&vars, argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_width * TILE, vars.map_height * TILE, "Hello world!");
	//mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
}
