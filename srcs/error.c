/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:32:57 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 17:28:44 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	map_length(t_idx *c)
{
	int	i;

	i = 0;
	while (c->ds.map[i])
		i++;
	c->ds.map_length = i;
}

void	map_error(t_idx *c)
{
	int	i;
	int	j;
	int	check_dir;

	i = 0;
	check_dir = 0;
	map_length(c);
	while (c->ds.map[i])
	{
		j = 0;
		while (c->ds.map[i][j])
		{
			is_map_closed(c, i, j);
			if (c->ds.map[i][j] == 'E' || c->ds.map[i][j] == 'N'
				|| c->ds.map[i][j] == 'W' || c->ds.map[i][j] == 'S')
				check_dir++;
			else if (c->ds.map[i][j] != '0' && c->ds.map[i][j] != '1'
					&& c->ds.map[i][j] != '2' && c->ds.map[i][j] != ' ')
				ft_exit(c, "Error\nWrong char on map\n");
			j++;
		}
		i++;
	}
	if (check_dir != 1)
		ft_exit(c, "Error\nMultiple or no initial position\n");
}

void	is_map_closed(t_idx *c, int y, int x)
{
	if (x == 0 || y == 0)
	{
		if (c->ds.map[y][x] != '1' && c->ds.map[y][x] != ' ')
			ft_exit(c, "Error\nMap not closed\n");
	}
	else if (y == c->ds.map_length - 1)
	{
		if (c->ds.map[y][x] != '1' && c->ds.map[y][x] != ' ')
			ft_exit(c, "Error\nMap not closed\n");
	}
	else if (c->ds.map[y][x] == '0' || c->ds.map[y][x] == '2'
		|| c->ds.map[y][x] == 'S' || c->ds.map[y][x] == 'E'
		|| c->ds.map[y][x] == 'N' || c->ds.map[y][x] == 'W')
	{
		if (c->ds.map[y - 1][x] == ' ' || c->ds.map[y - 1][x] == '\0')
			ft_exit(c, "Error\nMap not closed\n");
		if (c->ds.map[y + 1][x] == ' ' || c->ds.map[y + 1][x] == '\0')
			ft_exit(c, "Error\nMap not closed\n");
		if (c->ds.map[y][x - 1] == ' ' || c->ds.map[y][x - 1] == '\0')
			ft_exit(c, "Error\nMap not closed\n");
		if (c->ds.map[y][x + 1] == ' ' || c->ds.map[y][x + 1] == '\0')
			ft_exit(c, "Error\nMap not closed\n");
	}
}
