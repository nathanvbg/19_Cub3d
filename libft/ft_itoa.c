/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:12:26 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/12 18:01:34 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		compteur;

	compteur = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		compteur++;
	}
	while (n > 0)
	{
		n /= 10;
		compteur++;
	}
	return (compteur);
}

char	*ft_itoa(int n)
{
	long int	i;
	size_t		compteur;
	char		*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = (long)n;
	compteur = ft_len(i);
	s = malloc((compteur + 1) * sizeof(*s));
	if (s == NULL)
		return (NULL);
	if (i == 0)
		s[compteur - 1] = 0 + '0';
	if (i < 0)
		s[0] = '-';
	if (i < 0)
		i = -i;
	s[compteur] = '\0';
	while (i > 0)
	{
		compteur--;
		s[compteur] = (i % 10) + '0';
		i /= 10;
	}
	return (s);
}
