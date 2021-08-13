/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:40:28 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 17:43:27 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_end_pos(void)
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if (g_bits[i] == -1)
			break ;
		i--;
	}
	//printf("end_pos: %d\n", i);
	return (i);
}

static int	binary_pow(int a, int b)
{
	int	ans;

	ans = 1;
	if (b == 0)
		return (1);
	while (b > 0)
	{
		ans = ans * a;
		b--;
	}
	return (ans);
}

static int	bit_to_ascii(void)
{
	int	i;
	int	ascii;

	ascii = 0;
	i = -1;
	while (++i < 7)
		ascii += binary_pow(2, 6 - i) * g_bits[i];
	printf("ascii: %d\n", ascii);
	return (ascii);
}

void	mt_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	int		end_pos;
	int		new_bit;
	char	ascii_char;

	(void)info;
	(void)ucontext;
	new_bit = -2;
	if (sig == 30)
		new_bit = 0;
	else if (sig == 31)
		new_bit = 1;
	end_pos = get_end_pos();
	if (end_pos == -1)
	{
		mt_init_bits();
		g_bits[6] = new_bit;
	}
	else if (end_pos == 0)
	{
		g_bits[end_pos] = new_bit;
		ascii_char = (char)bit_to_ascii();
		write(1, &ascii_char, 1);
	}
	else
		g_bits[end_pos] = new_bit;
	int i = -1;
	while (++i < 7)
		printf("bits[%d]: %d\n", i, g_bits[i]);
}

int	main(void)
{
	char				*pid;
	struct sigaction	sigusr;

	pid = mt_ft_itoa((long)getpid());
	write(1, pid, (int)mt_ft_strlen(pid));
	write(1, "\n", 1);
	mt_ft_bzero(&sigusr, sizeof(struct sigaction));
	sigusr.sa_sigaction = mt_sig_handler;
	sigemptyset(&sigusr.sa_mask);
	sigusr.sa_flags = SA_SIGINFO;
	mt_init_bits();
	int i = -1;
	while (++i < 7)
		printf("bits[%d]: %d\n", i, g_bits[i]);
	if (sigaction(SIGUSR1, &sigusr, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, &sigusr, NULL) < 0)
		exit(1);
	while (1)
		continue ;
	return (0);
}
