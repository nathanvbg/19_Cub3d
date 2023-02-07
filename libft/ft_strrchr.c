/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:29:54 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 12:38:34 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	while (i >= 0)
	{
		if (*s == c)
			return (s);
		i--;
		s--;
	}
	return (NULL);
}
