/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:51:03 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 17:25:37 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	create_header(int fd, t_idx *c, int file_size)
{
	char	header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char) 'B';
	header[1] = (unsigned char) 'M';
	header[2] = (unsigned char)(file_size);
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(c->ds.screen.x);
	header[19] = (unsigned char)(c->ds.screen.x >> 8);
	header[20] = (unsigned char)(c->ds.screen.x >> 16);
	header[21] = (unsigned char)(c->ds.screen.x >> 24);
	header[22] = (unsigned char)((-1) * c->ds.screen.y);
	header[23] = (unsigned char)((-1) * c->ds.screen.y >> 8);
	header[24] = (unsigned char)((-1) * c->ds.screen.y >> 16);
	header[25] = (unsigned char)((-1) * c->ds.screen.y >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

void	bmp(t_idx *c)
{
	int		fd;
	int		file_size;

	fd = open("./screenshot.bmp", O_WRONLY | O_CREAT
			| O_TRUNC | O_APPEND, S_IRWXU);
	if (fd < 0)
		ft_exit(c, "Error\nThe screenshot has failed!\n");
	file_size = 54 + (c->ds.screen.x * c->ds.screen.y) * 4;
	create_header(fd, c, file_size);
	write(fd, (char *)c->img.addr, (c->ds.screen.x * c->ds.screen.y * 4));
	close(fd);
}
