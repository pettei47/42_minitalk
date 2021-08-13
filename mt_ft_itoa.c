/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:05:27 by teppei            #+#    #+#             */
/*   Updated: 2021/08/13 14:25:07 by teppei           ###   ########.fr       */
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

void	*mt_ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = (void *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	mt_ft_memset(mem, 0, nmemb * size);
	return (mem);
}

static size_t	digit(long a)
{
	size_t	i;
	long	b;

	i = 0;
	b = a;
	if (b == 0)
		return (1);
	if (b < 0)
	{
		b *= -1;
		i++;
	}
	while (b > 0)
	{
		b /= 10;
		i++;
	}
	return (i);
}

static char	*swap(char *s, size_t len)
{
	char	tmp;
	size_t	i;

	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
	return (s);
}

char	*mt_ft_itoa(long n)
{
	char	*out;
	size_t	i;
	size_t	dig;

	dig = digit(n);
	i = 0;
	out = (char *)mt_ft_calloc(sizeof(char), (dig + 1));
	if (!out)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		out[dig - 1] = '-';
		dig--;
	}
	while (i < dig)
	{
		out[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	out = swap(out, mt_ft_strlen(out));
	return (out);
}
