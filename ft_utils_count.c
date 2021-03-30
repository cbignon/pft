/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:48:00 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/30 21:55:32 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

unsigned int	ft_count_hexa(unsigned long long n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

unsigned int	ft_count_digit(long int n)
{
	unsigned int	count;
	unsigned int	nb;

	if (n < 0)
	{
		nb = (unsigned)-(long)n;
		count = 2;
	}
	else
	{
		nb = n;
		count = 1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

size_t			ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[len] != '\0')
		len++;
	return (len);
}
