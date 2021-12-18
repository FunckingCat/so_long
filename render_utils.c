/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:16:50 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/18 16:26:49 by tyamcha          ###   ########.fr       */
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