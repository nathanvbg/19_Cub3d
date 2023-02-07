/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:25:04 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/12 14:00:10 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	position_init(t_idx *c)
{
	int	i;
	int	j;

	i = 0;
	while (c->ds.map[i])
	{
		j = 0;
		while (c->ds.map[i][j])
		{
			if (ft_isalpha(c->ds.map[i][j]) == 1)
			{
				c->dda.pos.x = j + 0.5;
				c->dda.pos.y = i + 0.5;
				def_direction(c, c->ds.map[i][j]);
				c->ds.map[i][j] = '0';
			}
			if (c->ds.map[i][j] == '2')
				c->spr.spr_count++;
			j++;
		}
		i++;
	}
	c->ds.max.x = j;
	c->ds.max.y = i;
}

void	def_direction(t_idx *c, char pos)
{
	c->dda.dir.x = 0;
	c->dda.dir.y = 0;
	c->dda.plane.x = 0;
	c->dda.plane.y = 0;
	if (pos == 'S')
	{
		c->dda.dir.y = 1;
		c->dda.plane.x = -0.66;
	}
	if (pos == 'N')
	{
		c->dda.dir.y = -1;
		c->dda.plane.x = 0.66;
	}
	if (pos == 'W')
	{
		c->dda.dir.x = -1;
		c->dda.plane.y = -0.66;
	}
	if (pos == 'E')
	{
		c->dda.dir.x = 1;
		c->dda.plane.y = 0.66;
	}
}
