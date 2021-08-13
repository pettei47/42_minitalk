/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_ft_bzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:45:54 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 14:47:34 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*mt_ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*q;

	i = 0;
	q = (unsigned char *)s;
	while (i < n)
	{
		q[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	mt_ft_bzero(void *s, size_t n)
{
	mt_ft_memset(s, 0, n);
}
