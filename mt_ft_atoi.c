/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_ft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:43:57 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 14:17:02 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	mt_ft_atoi(char *str)
{
	long			i;
	long			sign;
	long			len;
	unsigned long	nbr;

	i = 0;
	sign = 1;
	len = 0;
	nbr = 0;
	while (str[i] == ' ' || (8 < str[i] && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
