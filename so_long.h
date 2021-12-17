/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:22:06 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/17 20:19:23 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include <mlx.h>

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	size_t		map_width;
	size_t		map_height;
}				t_vars;

void	error(char *name, char *desc);
void	read_map(t_vars *vars, char *path);

#endif