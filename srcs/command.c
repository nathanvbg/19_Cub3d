/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:40:34 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/14 16:14:13 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	command_vertical(int key, t_idx *c)
{
	double	speed;

	speed = 0.3;
	if (key == 53)
		ft_exit(c, "\nESCAPE KEY PRESSED\n");
	if (key == 13)
	{
		if (c->ds.map [(int)c->dda.pos.y]
			[(int)(c->dda.pos.x + c->dda.dir.x * speed)] == '0')
			c->dda.pos.x += c->dda.dir.x * speed;
		if (c->ds.map[(int)(c->dda.pos.y + c->dda.dir.y * speed)]
			[(int)c->dda.pos.x] == '0')
			c->dda.pos.y += c->dda.dir.y * speed;
	}
	if (key == 1)
	{
		if (c->ds.map[(int)c->dda.pos.y]
			[(int)(c->dda.pos.x - c->dda.dir.x * speed)] == '0')
			c->dda.pos.x -= c->dda.dir.x * speed;
		if (c->ds.map[(int)(c->dda.pos.y - c->dda.dir.y * speed)]
			[(int)c->dda.pos.x] == '0')
			c->dda.pos.y -= c->dda.dir.y * speed;
	}
	command_horizontal(key, c, speed);
	return (0);
}

int	command_horizontal(int key, t_idx *c, double speed)
{
	if (key == 2)
	{
		if (c->ds.map[(int)c->dda.pos.y]
			[(int)(c->dda.pos.x + c->dda.dir.x * speed)] == '0')
			c->dda.pos.x -= c->dda.dir.y * speed;
		if (c->ds.map[(int)(c->dda.pos.y + c->dda.dir.y * speed)]
			[(int)c->dda.pos.x] == '0')
			c->dda.pos.y += c->dda.dir.x * speed;
	}
	if (key == 0)
	{
		if (c->ds.map[(int)c->dda.pos.y]
			[(int)(c->dda.pos.x - c->dda.dir.x * speed)] == '0')
			c->dda.pos.x += c->dda.dir.y * speed;
		if (c->ds.map[(int)(c->dda.pos.y - c->dda.dir.y * speed)]
			[(int)c->dda.pos.x] == '0')
			c->dda.pos.y -= c->dda.dir.x * speed;
	}
	command_rotation(key, c);
	return (0);
}

int	command_rotation(int key, t_idx *c)
{
	double	rot;

	rot = 0.2;
	if (key == 123)
	{
		c->dda.olddir.x = c->dda.dir.x;
		c->dda.dir.x = c->dda.dir.x * cos(-rot) - c->dda.dir.y * sin(-rot);
		c->dda.dir.y = c->dda.olddir.x * sin(-rot) + c->dda.dir.y * cos(-rot);
		c->dda.oldplx = c->dda.plane.x;
		c->dda.plane.x = c->dda.plane.x * cos(-rot) - c->dda.plane.y
			* sin(-rot);
		c->dda.plane.y = c->dda.oldplx * sin(-rot) + c->dda.plane.y * cos(-rot);
	}
	if (key == 124)
	{
		c->dda.olddir.x = c->dda.dir.x;
		c->dda.dir.x = c->dda.dir.x * cos(rot) - c->dda.dir.y * sin(rot);
		c->dda.dir.y = c->dda.olddir.x * sin(rot) + c->dda.dir.y * cos(rot);
		c->dda.oldplx = c->dda.plane.x;
		c->dda.plane.x = c->dda.plane.x * cos(rot) - c->dda.plane.y * sin(rot);
		c->dda.plane.y = c->dda.oldplx * sin(rot) + c->dda.plane.y * cos(rot);
	}
	mlx_clear_window(c->img.ptr, c->win_ptr);
	algo(c);
	return (0);
}

int	red_cross(t_idx *c)
{
	ft_exit(c, "\nRED CROSS HAS BEEN PRESSED\n");
	return (0);
}
