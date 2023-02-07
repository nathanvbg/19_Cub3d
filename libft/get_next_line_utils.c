/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:29:11 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 13:53:02 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(const char *str)
{
	int	compteur;

	compteur = 0;
	while (str[compteur])
		compteur++;
	return (compteur);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	dst = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2))
			+ 1 * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*str1;
	char	*str_copy;
	int		i;
	int		len;

	i = 0;
	len = 0;
	str1 = (char *)s1;
	while (str1[len] != '\0')
		len++;
	str_copy = (char *)malloc(len + 1);
	if (str_copy == NULL)
		return (NULL);
	while (str1[i])
	{
		str_copy[i] = str1[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

char	*ft_strndup_gnl(const char *s1)
{
	char	*str1;
	char	*str_copy;
	int		i;
	int		len;

	i = 0;
	len = 0;
	str1 = (char *)s1;
	while (str1[len] != '\n' && str1[len] != '\0')
		len++;
	str_copy = (char *)malloc(len + 1);
	if (str_copy == NULL)
		return (NULL);
	while (str1[i] && str1[i] != '\n')
	{
		str_copy[i] = str1[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

char	*ft_strchr_gnl(const char *str)
{
	size_t	i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i + 1]);
		i++;
	}
	if (s[i] == '\n')
		return (&s[i]);
	return (NULL);
}
