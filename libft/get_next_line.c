/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:53:16 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 16:01:58 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUF_SIZE 10

int	ft_free(char **str, int n)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (n);
}

int	ft_init_run(int fd, char **line, char *rest)
{
	if (rest == NULL)
	{
		*line = ft_strndup_gnl("");
		if (*line == NULL)
			return (-1);
	}
	if (rest != NULL)
	{
		*line = ft_strdup_gnl(rest);
		if (*line == NULL)
			return (-1);
		free(rest);
	}
	return (ft_run(fd, line));
}

int	ft_run(int fd, char **line)
{
	int		ret;
	char	*buf;
	char	*temp;

	buf = malloc(BUF_SIZE + 1 * sizeof(char));
	if (buf == NULL)
		return (-1);
	if (ft_strchr_gnl(*line) == NULL)
		ret = read(fd, buf, BUF_SIZE);
	while (ft_strchr_gnl(*line) == NULL && ret > 0)
	{
		temp = *line;
		buf[ret] = '\0';
		*line = ft_strjoin_gnl(*line, buf);
		if (*line == NULL)
			return (-1);
		free(temp);
		if (ft_strchr_gnl(*line) == NULL)
			ret = read(fd, buf, BUF_SIZE);
	}
	free(buf);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX];
	char		*temp;

	if (fd < 0 || BUF_SIZE <= 0 || line == NULL)
		return (-1);
	if (ft_init_run(fd, line, rest[fd]) == -1)
		return (ft_free(&rest[fd], -1));
	if (rest[fd] != NULL)
		rest[fd] = NULL;
	if (ft_strchr_gnl(*line) == NULL)
		return (ft_free(&rest[fd], 0));
	rest[fd] = ft_strdup_gnl(ft_strchr_gnl(*line));
	if (rest[fd] == NULL)
		return (ft_free(&rest[fd], -1));
	temp = *line;
	*line = ft_strndup_gnl(*line);
	if (*line == NULL)
		return (ft_free(&rest[fd], -1));
	free(temp);
	return (1);
}
