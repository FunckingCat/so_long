/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:17:12 by unix              #+#    #+#             */
/*   Updated: 2021/12/17 20:18:05 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_symbols(t_vars *vars)
{
	int	i;
	int	j;
	int	player;
	int	out;

	i = 0;
	player = 0;
	out = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (j < vars->map_width)
		{
			if (vars->map[i][j] == 'P' && player)
				error("not valid map", "more then one player");
			if (vars->map[i][j] == 'P' && !player)
				player++;
			if (vars->map[i][j] == 'E')
				out++;
			if (!ft_strchr("01ECGP", vars->map[i][j]))
				error("not valid map", "not walid symbols");
			j++;
		}
		i++;
	}
	if (!player || !out)
		error("not valid map", "no player or out on the map");
}

void	validate_map(t_vars *vars)
{
	int		i;

	vars->map_width = ft_strlen(vars->map[0]);
	i = 1;
	while (i < vars->map_height)
		if (ft_strlen(vars->map[i++]) != vars->map_width)
			error("not valid map", "map must be rectangular");
	i = 0;
	while (i < vars->map_width)
		if (vars->map[0][i] != '1' || \
			vars->map[vars->map_height - 1][i++] != '1')
			error("not valid map", "map not surrounded by walls");
	i = 0;
	while (i < vars->map_height)
		if (vars->map[i][0] != '1' || \
			vars->map[i++][vars->map_width - 1] != '1')
			error("not valid map", "map not surrounded by walls");
	check_symbols(vars);
}

void	read_map(t_vars *vars, char *path)
{
	int		map_fd;
	char	*line;
	int		n;

	map_fd = open(path, O_RDONLY);
	if (map_fd == 1)
		error("map", "no such file or directory");
	n = 0;
	line = get_next_line(map_fd);
	while (line && n++ > -1)
	{
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	vars->map_height = n;
	vars->map = malloc(n * sizeof(char *) + 1);
	if (!vars->map)
		error("malloc", "alocation failed");
	map_fd = open(path, O_RDONLY);
	n = 0;
	vars->map[n] = get_next_line(map_fd);
	while (vars->map[n++])
		vars->map[n] = get_next_line(map_fd);
	close(map_fd);
	validate_map(vars);
}