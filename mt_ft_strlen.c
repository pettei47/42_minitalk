/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_ft_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:20:23 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 14:20:42 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	mt_ft_strlen(char *s)
{
	long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}