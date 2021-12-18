/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:17:12 by unix              #+#    #+#             */
/*   Updated: 2021/12/18 11:23:03 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_symbols(t_vars *vars)
{
	int	ij[2];
	int	plout[2];

	ij[0] = 0;
	plout[0] = 0;
	plout[1] = 0;
	while (ij[0] < vars->map_height)
	{
		ij[1] = 0;
		while (ij[1] < vars->map_width)
		{
			if (vars->map[ij[0]][ij[1]] == 'P' && plout[0])
				error("not valid map", "more then one player");
			if (vars->map[ij[0]][ij[1]] == 'P' && !plout[0])
				plout[0]++;
			if (vars->map[ij[0]][ij[1]] == 'E')
				plout[1]++;
			if (!ft_strchr("01ECGP", vars->map[ij[0]][ij[1]++]))
				error("not valid map", "not walid symbols");
		}
		ij[0]++;
	}
	if (!plout[0] || !plout[1])
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

int	count_lines(char *path)
{
	int		map_fd;
	char	*line;
	int		n;

	map_fd = open(path, O_RDONLY);
	if (map_fd == 1)
		error("map", "no such file or directory");
	n = 0;
	line = get_next_line(map_fd);
	while (1)
	{
		line = get_next_line(map_fd);
		if (line)
		{
			free(line);
			n++;
		}
		else
			break ;
	}
	close(map_fd);
	return (n + 1);
}

void	read_map(t_vars *vars, char *path)
{
	int		map_fd;
	char	*line;
	int		n;

	vars->map_height = count_lines(path);
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