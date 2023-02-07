/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:41:07 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/21 14:50:05 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parsing(t_idx *c, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_exit(c, "Error\nFile won't open\n");
	gnl_info(c, fd);
	gnl_map(c, fd);
	adjust_map(c);
	map_error(c);
	position_init(c);
	if (close(fd) < 0)
		ft_exit(c, "Error\nfile won't close\n");
}

void	gnl_info(t_idx *c, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < 8)
	{
		if (!get_next_line(fd, &line))
		{
			free(line);
			ft_exit(c, "Error\nGnl error\n");
		}
		if (!line_empty(line))
		{
			parse_info(line, c);
			i++;
		}
		free(line);
	}
}

void	parse_info(char *line, t_idx *c)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == 9)
		i++;
	if (strncmp(&line[i], "R ", 2) == 0)
		def_resolution(c, &line[i]);
	else if (strncmp(&line[i], "F ", 2) == 0)
		def_floor_ceiling(c, &line[i], &c->ds.fl);
	else if (strncmp(&line[i], "C ", 2) == 0)
		def_floor_ceiling(c, &line[i], &c->ds.c);
	else if (strncmp(&line[i], "NO ", 3) == 0)
		def_text_path(c, &c->ds.text_path_no, &line[i]);
	else if (strncmp(&line[i], "EA ", 3) == 0)
		def_text_path(c, &c->ds.text_path_ea, &line[i]);
	else if (strncmp(&line[i], "WE ", 3) == 0)
		def_text_path(c, &c->ds.text_path_we, &line[i]);
	else if (strncmp(&line[i], "SO ", 3) == 0)
		def_text_path(c, &c->ds.text_path_so, &line[i]);
	else if (strncmp(&line[i], "S ", 2) == 0)
		def_text_path(c, &c->ds.text_path_s, &line[i]);
	else
		ft_exit(c, "Error\nWrong info line\n");
}
