/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:22:06 by tyamcha           #+#    #+#             */
/*   Updated: 2021/12/18 17:55:49 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"

#define TILE 64
#define HERO   "./assets/hero/hero00.xpm"
#define HERO1  "./assets/hero/hero01.xpm"
#define HERO2  "./assets/hero/hero02.xpm"
#define HERO3  "./assets/hero/hero03.xpm"
#define GOST   "./assets/gost/gost00.xpm"
#define GOST1  "./assets/gost/gost01.xpm"
#define GOST2  "./assets/gost/gost02.xpm"
#define GOST3  "./assets/gost/gost03.xpm"
#define COIN   "./assets/land/collectible.xpm"
#define WALL   "./assets/land/wall.xpm"
#define OUT    "./assets/land/out.xpm"
#define GROUND "./assets/land/ground.xpm"

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	int			steps;
	size_t		map_width;
	size_t		map_height;
	int			pl_x;
	int			pl_y;
}				t_vars;

void	error(char *name, char *desc);
void	read_map(t_vars *vars, char *path);
void	put_image(t_vars *vars, char *path, int	x, int 	y);
int		render_frame(t_vars *vars);

#endif