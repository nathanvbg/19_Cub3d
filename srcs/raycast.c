/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:46:09 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/14 16:12:09 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_map_var1(t_idx *c, int x)
{
	c->dda.camx = 2 * x / (double)c->ds.screen.x - 1;
	c->dda.raydir.x = c->dda.dir.x + c->dda.plane.x * c->dda.camx;
	c->dda.raydir.y = c->dda.dir.y + c->dda.plane.y * c->dda.camx;
	c->dda.map.x = (int)c->dda.pos.x;
	c->dda.map.y = (int)c->dda.pos.y;
	if (c->dda.raydir.y == 0)
		c->dda.distbetween.x = 0;
	else if (c->dda.raydir.x == 0)
		c->dda.distbetween.x = 1;
	else
		c->dda.distbetween.x = fabs(1 / c->dda.raydir.x);
	if (c->dda.raydir.x == 0)
		c->dda.distbetween.y = 0;
	else if (c->dda.raydir.y == 0)
		c->dda.distbetween.y = 1;
	else
		c->dda.distbetween.y = fabs(1 / c->dda.raydir.y);
}

void	init_map_var2(t_idx *c)
{
	if (c->dda.raydir.x < 0)
	{
		c->dda.jump.x = -1;
		c->dda.distnext.x = (c->dda.pos.x - c->dda.map.x)
			* c->dda.distbetween.x;
	}
	else
	{
		c->dda.jump.x = 1;
		c->dda.distnext.x = (c->dda.map.x + 1.0 - c->dda.pos.x)
			* c->dda.distbetween.x;
	}
	if (c->dda.raydir.y < 0)
	{
		c->dda.jump.y = -1;
		c->dda.distnext.y = (c->dda.pos.y - c->dda.map.y)
			* c->dda.distbetween.y;
	}
	else
	{
		c->dda.jump.y = 1;
		c->dda.distnext.y = (c->dda.map.y + 1.0 - c->dda.pos.y)
			* c->dda.distbetween.y;
	}
}

void	dda(t_idx *c)
{
	while (c->dda.hit == 0)
	{
		if (c->dda.distnext.x < c->dda.distnext.y)
		{
			c->dda.distnext.x += c->dda.distbetween.x;
			c->dda.map.x += c->dda.jump.x;
			c->dda.side = 0;
		}
		else
		{
			c->dda.distnext.y += c->dda.distbetween.y;
			c->dda.map.y += c->dda.jump.y;
			c->dda.side = 1;
		}
		if (c->ds.map[c->dda.map.y][c->dda.map.x] == '1')
			c->dda.hit = 1;
	}
}

void	line_height(t_idx *c)
{
	if (c->dda.side == 0)
		c->dda.wallperp = (c->dda.map.x - c->dda.pos.x
				+ (1 - c->dda.jump.x) / 2) / c->dda.raydir.x;
	else
		c->dda.wallperp = (c->dda.map.y - c->dda.pos.y
				+ (1 - c->dda.jump.y) / 2) / c->dda.raydir.y;
	if (c->dda.wallperp == 0)
		c->dda.wallperp = 0.1;
	if (c->dda.side == 0)
		c->dda.wall_x = c->dda.pos.y + c->dda.wallperp * c->dda.raydir.y;
	else
		c->dda.wall_x = c->dda.pos.x + c->dda.wallperp * c->dda.raydir.x;
	c->dda.wall_x -= floor(c->dda.wall_x);
	c->dda.lineheight = abs((int)(c->ds.screen.y / c->dda.wallperp));
	c->dda.drawmin = -c->dda.lineheight / 2 + c->ds.screen.y / 2;
	if (c->dda.drawmin < 0)
		c->dda.drawmin = 0;
	c->dda.drawmax = c->dda.lineheight / 2 + c->ds.screen.y / 2;
	if (c->dda.drawmax >= c->ds.screen.y)
		c->dda.drawmax = c->ds.screen.y;
}

void	draw_line(t_img *text_img, t_idx *c, int x)
{
	int	y;

	y = 0;
	while (y < c->dda.drawmin)
	{
		c->img.addr[y * c->ds.screen.x + x] = c->ds.c;
		y++;
	}
	c->dda.step = 1.0 * text_img->size.y / c->dda.lineheight;
	c->dda.texpos = (c->dda.drawmin - c->ds.screen.y / 2
			+ c->dda.lineheight / 2) * c->dda.step;
	while (y < c->dda.drawmax)
	{
		c->dda.text.y = (int)c->dda.texpos & (text_img->size.y - 1);
		c->dda.texpos += c->dda.step;
		c->img.addr[y * c->ds.screen.x + x] = text_img->addr[(text_img->size.y
				* c->dda.text.y + c->dda.text.x)];
		y++;
	}
	while (y < c->ds.screen.y - 1)
	{
		c->img.addr[y * c->ds.screen.x + x] = c->ds.fl;
		y++;
	}
}
