/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:57:17 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 12:38:12 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*haystack;
	char	*needle;

	i = 0;
	haystack = (char *)s1;
	needle = (char *)s2;
	if (needle[i] == '\0')
		return (haystack);
	while (i < n && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < n)
		{
			j++;
			if (needle[j] == '\0')
				return (&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
