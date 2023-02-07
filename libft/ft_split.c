/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:15:20 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/15 11:07:02 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_c(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

static void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_create_str(char const *s, char c, char **tab)
{
	size_t			i;
	unsigned int	j;
	char			*dst;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	dst = ft_substr(s, j, i);
	if (dst == NULL)
		ft_free(tab);
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	tab = malloc((ft_count_c(s, c) + 2) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j] = ft_create_str(&s[i], c, tab);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[j] = (NULL);
	return (tab);
}
