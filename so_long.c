/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:22:02 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/18 16:38:10 by tyamcha          ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	int		a, b;

	t_vars	vars;
	void	*img;

	if (argc != 2)
		error("invalid args", "usage: ./so_long map.ber");
	read_map(&vars, argv[1]);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_width * TILE, vars.map_height * TILE, "Hello world!");
	render_map(&vars);
	mlx_loop(vars.mlx);
}
