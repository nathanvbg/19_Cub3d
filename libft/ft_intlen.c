/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:05:19 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/12 17:47:22 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb)
{
	int	compteur;

	compteur = 0;
	if (nb < 0)
	{
		compteur++;
		nb = nb * -1;
	}
	if (nb == 0)
		return (1);
	while (nb > 10)
	{
		nb = nb / 10;
		compteur++;
	}
	if (nb >= 1 && nb <= 9)
		compteur++;
	return (compteur);
}
