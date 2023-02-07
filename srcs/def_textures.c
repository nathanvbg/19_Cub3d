/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:12:08 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/21 14:49:11 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	def_text_path(t_idx *c, char **text_path, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = &line[2];
	if (*text_path != NULL)
		ft_exit(c, "Error\nPath problem\n");
	while (tmp[i] == ' ' || tmp[i] == 9)
		i++;
	if (strncmp(&tmp[i], "./", 2) != 0)
		ft_exit(c, "Error\nPath problem");
	*text_path = ft_strdup_text(&tmp[i]);
	while (tmp[i] != ' ' && tmp[i] != 9 && tmp[i])
		i++;
	if (!line_empty(&tmp[i]))
		ft_exit(c, "Error\nPath problem");
}

void	init_texture(t_idx *c)
{
	define_texture(c, c->ds.text_path_we, &c->ds.text_we);
	define_texture(c, c->ds.text_path_so, &c->ds.text_so);
	define_texture(c, c->ds.text_path_no, &c->ds.text_no);
	define_texture(c, c->ds.text_path_ea, &c->ds.text_ea);
	define_texture(c, c->ds.text_path_s, &c->ds.text_s);
}

void	define_texture(t_idx *c, char *path, t_img *text)
{
	text->ptr = mlx_xpm_file_to_image(c->mlx_ptr, path, &text->size.x,
			&text->size.y);
	if (text->ptr == NULL)
		ft_exit(c, "Error\nTexture problem\n");
	text->addr = (int *)mlx_get_data_addr(text->ptr, &text->bbp, &text->size_l,
			&text->endian);
}

t_img	*get_texture_img(t_idx *c)
{
	t_img	*text_img;

	if (c->dda.side == 0)
	{
		if (c->dda.raydir.x > 0)
			text_img = &c->ds.text_ea;
		else
			text_img = &c->ds.text_we;
	}
	else
	{
		if (c->dda.raydir.y > 0)
			text_img = &c->ds.text_so;
		else
			text_img = &c->ds.text_no;
	}
	c->dda.text.x = (int)(c->dda.wall_x * (double)text_img->size.x);
	if (c->dda.side == 0 && c->dda.raydir.x > 0)
		c->dda.text.x = text_img->size.x - c->dda.text.x - 1;
	if (c->dda.side == 1 && c->dda.raydir.y < 0)
		c->dda.text.x = text_img->size.x - c->dda.text.x - 1;
	return (text_img);
}
