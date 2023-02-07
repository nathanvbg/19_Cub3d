/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:32:28 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/12 14:01:19 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_exit(t_idx *c, char *str)
{
	if (c->img.ptr != NULL && c->win_ptr != NULL)
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
	free_map(c);
	free_text(c);
	free_sprites(c);
	ft_putstr(str);
	exit(0);
}

void	free_map(t_idx *c)
{
	int	i;

	i = 0;
	if (c->ds.map != NULL)
	{
		while (c->ds.map && c->ds.map[i])
		{
			free_str(&c->ds.map[i]);
			i++;
		}
		free(c->ds.map);
		c->ds.map = NULL;
	}
}

void	free_sprites(t_idx *c)
{
	if (c->spr.sprite_x != NULL)
		free(c->spr.sprite_x);
	c->spr.sprite_x = NULL;
	if (c->spr.sprite_y != NULL)
		free(c->spr.sprite_y);
	c->spr.sprite_y = NULL;
	if (c->spr.distance != NULL)
		free(c->spr.distance);
	c->spr.distance = NULL;
	if (c->spr.zbuffer != NULL)
		free(c->spr.zbuffer);
	c->spr.zbuffer = NULL;
}

void	free_text(t_idx *c)
{
	free_str(&c->ds.text_path_no);
	free_str(&c->ds.text_path_so);
	free_str(&c->ds.text_path_we);
	free_str(&c->ds.text_path_ea);
	free_str(&c->ds.text_path_s);
	if (c->ds.text_no.ptr != 0)
		mlx_destroy_image(c->mlx_ptr, c->ds.text_no.ptr);
	c->ds.text_no.ptr = NULL;
	if (c->ds.text_so.ptr != 0)
		mlx_destroy_image(c->mlx_ptr, c->ds.text_so.ptr);
	c->ds.text_so.ptr = NULL;
	if (c->ds.text_ea.ptr != 0)
		mlx_destroy_image(c->mlx_ptr, c->ds.text_ea.ptr);
	c->ds.text_ea.ptr = NULL;
	if (c->ds.text_we.ptr != 0)
		mlx_destroy_image(c->mlx_ptr, c->ds.text_we.ptr);
	c->ds.text_we.ptr = NULL;
}
