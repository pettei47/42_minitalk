/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:01:02 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 17:36:42 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int	g_bits[7];

size_t	mt_ft_strlen(char *s);
long	mt_ft_atoi(char *s);
char	*mt_ft_itoa(long n);
void	mt_ft_bzero(void *mem, size_t n);
void	mt_init_bits(void);

#endif