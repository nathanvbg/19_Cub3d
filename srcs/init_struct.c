/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:55:18 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/20 14:51:10 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	malloc_sprites(t_idx *c)
{
	c->spr.sprite_x = malloc((c->spr.spr_count + 1) * sizeof(double));
	if (c->spr.sprite_x == NULL)
		ft_exit(c, "Error\nSprite malloc error\n");
	c->spr.sprite_y = malloc((c->spr.spr_count + 1) * sizeof(double));
	if (c->spr.sprite_y == NULL)
		ft_exit(c, "Error\nSprite malloc error\n");
	c->spr.distance = malloc((c->spr.spr_count + 1) * sizeof(double));
	if (c->spr.distance == NULL)
		ft_exit(c, "Error\nSprite malloc error\n");
	c->spr.zbuffer = malloc((c->ds.screen.x + 1) * sizeof(double));
	if (c->spr.zbuffer == NULL)
		ft_exit(c, "Error\nZbuffer malloc error\n");
}

void	init_sprites(t_idx *c)
{
	c->spr.spr_count = 0;
	c->spr.sprite_x = NULL;
	c->spr.sprite_y = NULL;
	c->spr.distance = NULL;
	c->spr.zbuffer = NULL;
	c->spr.check = 0;
	c->spr.spritex = 0;
	c->spr.spritey = 0;
	c->spr.invdet = 0;
	c->spr.spr_screenx = 0;
	c->spr.width = 0;
	c->spr.height = 0;
	c->spr.stripe = 0;
	c->ds.nb1 = 0;
	c->ds.nb2 = 0;
	c->ds.nb3 = 0;
}

void	init_design(t_idx *c)
{
	c->mlx_ptr = NULL;
	c->win_ptr = NULL;
	c->img.ptr = NULL;
	c->img.addr = NULL;
	c->ds.fl = 0;
	c->ds.c = 0;
	c->ds.text_path_no = NULL;
	c->ds.text_path_so = NULL;
	c->ds.text_path_ea = NULL;
	c->ds.text_path_we = NULL;
	c->ds.text_path_s = NULL;
	c->ds.text_no.ptr = NULL;
	c->ds.text_so.ptr = NULL;
	c->ds.text_ea.ptr = NULL;
	c->ds.text_we.ptr = NULL;
	c->ds.text_no.addr = NULL;
	c->ds.text_so.addr = NULL;
	c->ds.text_ea.addr = NULL;
	c->ds.text_we.addr = NULL;
	c->ds.map = NULL;
	c->ds.screen.x = 0;
	c->ds.screen.y = 0;
	c->dda.drawmin = 0;
	c->dda.drawmax = 0;
	c->dda.texpos = 0;
}

void	init_dda(t_idx *c)
{
	c->dda.pos.x = 0;
	c->dda.pos.y = 0;
	c->dda.dir.x = 0;
	c->dda.dir.y = 0;
	c->dda.olddir.x = 0;
	c->dda.olddir.y = 0;
	c->dda.plane.x = 0;
	c->dda.plane.y = 0;
	c->dda.oldplx = 0;
	c->dda.camx = 0;
	c->dda.raydir.x = 0;
	c->dda.raydir.y = 0;
	c->dda.map.x = 0;
	c->dda.map.y = 0;
	c->dda.distbetween.x = 0;
	c->dda.distbetween.y = 0;
	c->dda.distnext.x = 0;
	c->dda.distnext.y = 0;
	c->dda.wall_x = 0;
	c->dda.jump.x = 0;
	c->dda.jump.y = 0;
	c->dda.step = 0;
	c->dda.side = 0;
	c->dda.wallperp = 0;
	c->dda.lineheight = 0;
}

void	init(t_idx *c)
{
	init_design(c);
	init_dda(c);
	init_sprites(c);
}
