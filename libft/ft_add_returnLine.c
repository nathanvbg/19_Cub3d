/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_returnline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:00:15 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/12 17:41:34 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_returnline(char *str)
{
	char	*dst;
	int		i;

	if (str == NULL)
		return (NULL);
	dst = malloc((ft_strlen((char *)str) + 2 * sizeof(char)));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i++] = '\n';
	dst[i] = '\0';
	return (dst);
}
