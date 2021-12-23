/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:01:09 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/23 14:26:56 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == A_KEY)
		printf("A\n");
	if (keycode == S_KEY)
		printf("S\n");
	if (keycode == D_KEY)
		printf("D\n");
	if (keycode == W_KEY)
		printf("W\n");
	return (0);
}

int	mlx_close()
{
	printf("Game Closed\n");
	exit (EXIT_SUCCESS);
}