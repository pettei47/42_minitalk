/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:40:28 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 14:35:36 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	char				*pid;
	//struct sigaction	sigusr;

	pid = mt_ft_itoa((long)getpid());
	write(1, pid, (int)mt_ft_strlen(pid));
	write(1, "\n", 1);
	return (0);
}
