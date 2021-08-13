/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:02:13 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 17:49:31 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_cl_send_char(pid_t pid, char c)
{
	long	bit;
	long	i;

	if ((unsigned char)c > 127)
		return ;
	i = -1;
	while (++i < 7)
	{
		usleep(100);
		bit = ((unsigned char)c >> i) & 1;
		printf("%ld", bit);
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		if (bit == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit (1);
		}
	}
}

int	main(int ac, char **av)
{
	long	i;
	pid_t	pid;

	if (ac != 3)
		return (1);
	i = -1;
	pid = mt_ft_atoi(av[1]);
	while (av[2][++i])
		mt_cl_send_char(pid, av[2][i]);
	printf("\n");
	return (0);
}
