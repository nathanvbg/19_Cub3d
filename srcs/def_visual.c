/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_visual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:32:05 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/21 16:45:25 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	resolution_max(t_idx *c)
{
	if (c->ds.screen.x > 3200)
		c->ds.screen.x = 3200;
	if (c->ds.screen.y > 1756)
		c->ds.screen.y = 1756;
}

void	def_resolution(t_idx *c, char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]) || line[i] == 0)
		ft_exit(c, "Error\nResolution error\n");
	c->ds.screen.x = ft_atoi(&line[i], 0);
	line = str_pointer(&line[i]);
	i = 0;
	while (line[i] != ' ' && line[i] != '\0' && line[i] != 9)
	{
		if (!ft_isdigit(line[i]) || line[i] == 0)
			ft_exit(c, "Error\nResolution error\n");
		i++;
	}
	c->ds.screen.y = ft_atoi(&line[0], 0);
	resolution_max(c);
	if (c->ds.screen.y <= 0 || c->ds.screen.x <= 0)
		ft_exit(c, "Error\nResolution error\n");
	while (line[i++])
	{
		if (line[i] != ' ' && line[i] != '\0' && line[i] != 9)
			ft_exit(c, "Error\nResolution error\n");
	}
}

char	*str_pointer(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	return (&line[i]);
}

void	def_floor_ceiling(t_idx *c, char *line, int *color)
{
	int	i;

	i = 1;
	if (*color != 0)
		ft_exit(c, "\nError\nFloor or ceiling error\n");
	c->ds.nb1 = ft_atoi(&line[i], 0);
	while (ft_isdigit(line[i]) || line[i] == ' ')
		i++;
	if (line[i++] != ',')
		ft_exit(c, "\nError\nFloor or ceiling error\n");
	c->ds.nb2 = ft_atoi(&line[i], 0);
	while (ft_isdigit(line[i]) || line[i] == ' ')
		i++;
	if (line[i++] != ',')
		ft_exit(c, "\nError\nFloor or ceiling error\n");
	c->ds.nb3 = ft_atoi(&line[i], 0);
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	def_floor_ceiling_2(c, &line[i], color);
}

void	def_floor_ceiling_2(t_idx *c, char *line, int *color)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != 9)
			ft_exit(c, "Error\nFloor or ceiling error\n");
		i++;
	}
	*color = c->ds.nb1 * 65536 + c->ds.nb2 * 256 + c->ds.nb3;
	if (c->ds.nb1 < 0 || c->ds.nb1 > 255 || c->ds.nb2 < 0 || c->ds.nb2 > 255
		|| c->ds.nb3 < 0 || c->ds.nb3 > 255)
		ft_exit(c, "Error\nWrong pixel value\n");
	c->ds.nb1 = 0;
	c->ds.nb2 = 0;
	c->ds.nb3 = 0;
}
