/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:11:10 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/29 12:18:45 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	manage_sprites(t_idx *c)
{
	int		i;

	i = 0;
	sprites_position(c);
	sort_sprites(c);
	while (i < c->spr.spr_count)
	{
		transform_sprites(c, i);
		sprites_draw_limits(c);
		sprites_draw_line(c);
		i++;
	}
}

void	sprites_position(t_idx *c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (c->ds.map[i])
	{
		j = 0;
		while (c->ds.map[i][j])
		{
			if (c->ds.map[i][j] == '2')
			{
				c->spr.sprite_x[k] = j + 0.5;
				c->spr.sprite_y[k] = i + 0.5;
				c->ds.map[i][j] = '0';
				k++;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(t_idx *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < c->spr.spr_count - 1)
	{
		c->spr.check = 0;
		c->spr.distance[i] = ((c->dda.pos.x - c->spr.sprite_x[i])
				* (c->dda.pos.x - c->spr.sprite_x[i])
				+ (c->dda.pos.y - c->spr.sprite_y[i])
				* (c->dda.pos.y - c->spr.sprite_y[i]));
		j = i - 1;
		while (++j < c->spr.spr_count)
		{
			if (c->spr.distance[i] < ((c->dda.pos.x - c->spr.sprite_x[j])
					* (c->dda.pos.x - c->spr.sprite_x[j])
					+ (c->dda.pos.y - c->spr.sprite_y[j])
					* (c->dda.pos.y - c->spr.sprite_y[j])))
				ft_swap(c, i, j);
		}
		i++;
		if (c->spr.check == 1)
			i = 0;
	}
}

void	ft_swap(t_idx *c, int i, int j)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = c->spr.sprite_x[i];
	tmp_y = c->spr.sprite_y[i];
	c->spr.sprite_x[i] = c->spr.sprite_x[j];
	c->spr.sprite_y[i] = c->spr.sprite_y[j];
	c->spr.sprite_x[j] = tmp_x;
	c->spr.sprite_y[j] = tmp_y;
	c->spr.check = 1;
}
