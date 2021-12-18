/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:01:09 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/18 19:29:57 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	printf("KEY CODE %d\n", keycode);
	return (0);
}

int	mlx_close()
{
	printf("Game Closed");
	exit (EXIT_SUCCESS);
}