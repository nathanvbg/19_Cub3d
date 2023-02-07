/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:52:57 by nverbrug          #+#    #+#             */
/*   Updated: 2021/04/21 14:52:41 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int checker)
{
	int					sign;
	unsigned long int	nbr;
	int					i;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
		checker++;
	}
	if (nbr > 2147483648 && sign == -1)
		return (0);
	else if ((nbr > 2147483648 && sign == 1) || checker == 0)
		return (-1);
	return (nbr * sign);
}
