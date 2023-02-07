/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:52:57 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/20 18:02:40 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_text(const char *s1)
{
	char	*str1;
	char	*str_copy;
	int		i;

	i = 0;
	str1 = (char *)s1;
	str_copy = (char *)malloc(ft_strlen(str1) + 1);
	if (str_copy == NULL)
		return (NULL);
	while (str1[i] && str1[i] != ' ' && str1[i] != 9)
	{
		str_copy[i] = str1[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}
