/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 13:10:52 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/21 14:50:33 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	gnl_map(t_idx *c, int fd)
{
	char	*map;
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) == 1 && line_empty(line))
		free(line);
	map = ft_add_returnline(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		tmp = line;
		line = ft_strjoin(line, "\n");
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
	}
	tmp = map;
	map = ft_strjoin(map, line);
	check_empty_line(c, map);
	free(line);
	free(tmp);
	c->ds.map = ft_split(map, '\n');
	free(map);
}

int	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != 9 && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void	check_empty_line(t_idx *c, char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[i - 1] == '\n')
		i--;
	while (j < i - 1)
	{
		if (map[j] == '\n' && map[j + 1] == '\n')
			ft_exit(c, "Error\nEmpty line");
		j++;
	}
}

void	adjust_map(t_idx *c)
{
	int		max;
	int		i;
	char	*tmp;

	tmp = NULL;
	max = 0;
	i = 0;
	while (c->ds.map[i])
	{
		if ((int)ft_strlen(&c->ds.map[i][0]) > max)
			max = ft_strlen(&c->ds.map[i][0]);
		i++;
	}
	i = 0;
	while (c->ds.map[i])
	{
		if ((int)ft_strlen(&c->ds.map[i][0]) < max)
		{
			tmp = c->ds.map[i];
			c->ds.map[i] = ft_strdup_line(c->ds.map[i], max);
			free(tmp);
		}
		i++;
	}
}

char	*ft_strdup_line(char *line, int max)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc((max + 1) * sizeof(char));
	while (i < (int)ft_strlen(line))
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < max)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
