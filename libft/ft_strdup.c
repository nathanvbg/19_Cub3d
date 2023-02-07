/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:25:24 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/13 12:32:18 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str1;
	char	*str_copy;
	int		i;

	i = 0;
	str1 = (char *)s1;
	str_copy = (char *)malloc(ft_strlen(str1) + 1);
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
