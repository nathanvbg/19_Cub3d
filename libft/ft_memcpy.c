/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:44:01 by nverbrug          #+#    #+#             */
/*   Updated: 2019/11/23 18:08:48 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	if (!(src || dst))
		return (NULL);
	i = 0;
	s1 = (char *)src;
	s2 = (char *)dst;
	while (n > i)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
