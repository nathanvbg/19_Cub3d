/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:57:57 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/29 12:19:25 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	transform_sprites(t_idx *c, int i)
{
	c->spr.spritex = c->spr.sprite_x[i] - c->dda.pos.x;
	c->spr.spritey = c->spr.sprite_y[i] - c->dda.pos.y;
	c->spr.invdet = 1.0 / (c->dda.plane.x * c->dda.dir.y
			- c->dda.dir.x * c->dda.plane.y);
	c->spr.transform.x = c->spr.invdet * (c->dda.dir.y
			*c->spr.spritex - c->dda.dir.x * c->spr.spritey);
	c->spr.transform.y = c->spr.invdet * (-c->dda.plane.y
			* c->spr.spritex + c->dda.plane.x * c->spr.spritey);
	c->spr.spr_screenx = (int)((c->ds.screen.x / 2)
			* (1 + c->spr.transform.x / c->spr.transform.y));
}

void	sprites_draw_limits(t_idx *c)
{
	c->spr.height = (int)fabs((double)c->ds.screen.y
			/ c->spr.transform.y);
	c->spr.drawstart.y = -c->spr.height / 2 + c->ds.screen.y / 2;
	if (c->spr.drawstart.y < 0)
		c->spr.drawstart.y = 0;
	c->spr.drawend.y = c->spr.height / 2 + c->ds.screen.y / 2;
	if (c->spr.drawend.y >= c->ds.screen.y)
		c->spr.drawend.y = c->ds.screen.y - 1;
	c->spr.width = (int)fabs((double)c->ds.screen.y / c->spr.transform.y);
	c->spr.drawstart.x = -c->spr.width / 2 + c->spr.spr_screenx;
	if (c->spr.drawstart.x < 0)
		c->spr.drawstart.x = 0;
	c->spr.drawend.x = c->spr.width / 2 + c->spr.spr_screenx;
	if (c->spr.drawend.x >= c->ds.screen.x)
		c->spr.drawend.x = c->ds.screen.x - 1;
}

void	sprites_draw_line(t_idx *c)
{
	c->spr.stripe = c->spr.drawstart.x;
	while (c->spr.stripe < c->spr.drawend.x)
	{
		c->spr.text.x = (int)((c->spr.stripe - (-c->spr.width / 2
						+ c->spr.spr_screenx)) * 64 / c->spr.width);
		if (c->spr.transform.y > 0 && c->spr.stripe >= 0
			&& c->spr.stripe < c->ds.screen.x
			&& c->spr.transform.y < c->spr.zbuffer[c->spr.stripe])
			draw_sprites(c);
		c->spr.stripe++;
	}
}

void	draw_sprites(t_idx *c)
{
	int	y;
	int	i;

	i = 0;
	y = c->spr.drawstart.y;
	while (y < c->spr.drawend.y)
	{
		i = y * 256 - c->ds.screen.y * 128 + c->spr.height * 128;
		c->spr.text.y = ((i * 64) / c->spr.height) / 256;
		if (c->spr.text.y < 64 && ((c->ds.text_s.addr[64 * c->spr.text.y
						+ c->spr.text.x] & 0x00ffffff) != 0))
		{
			c->img.addr[y * c->ds.screen.x + c->spr.stripe]
				= c->ds.text_s.addr[64 * c->spr.text.y + c->spr.text.x];
		}
		y++;
	}
}
