/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:07:50 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 12:40:45 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	trim_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_check(s1[i], set) == 1)
			i++;
		else
			return (i);
	}
	return (i);
}

static int	trim_end(char const *s1, char const *set)
{
	int	i;
	int	compteur;

	i = ft_strlen((char *)s1) - 1;
	compteur = 0;
	while (i > 0)
	{
		if (ft_check(s1[i], set) == 1)
		{
			compteur++;
			i--;
		}
		else
			return (compteur);
	}
	return (compteur);
}

static char	*ft_null(void)
{
	char	*s;

	s = malloc(1 * sizeof(*s));
	if (s == NULL)
		return (NULL);
	s[0] = '\0';
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final_str;
	int		i;
	int		start;
	int		len;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = trim_start(s1, set);
	len = ft_strlen((char *)s1) - start - trim_end(s1, set);
	if (len < 0)
		return (ft_null());
	final_str = malloc((len + 1) * sizeof(*final_str));
	if (final_str == NULL)
		return (NULL);
	while (len > 0)
	{
		final_str[i] = s1[start];
		start++;
		i++;
		len--;
	}
	final_str[i] = '\0';
	return (final_str);
}
