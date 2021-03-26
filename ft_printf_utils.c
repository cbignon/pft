/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:54:29 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/26 18:06:23 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i])
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

void		ft_putnbr(int nb, int len_b, char *base, t_flags *flags)
{
	int		reste;
	long	nombre;

	nombre = nb;
	if (nombre < 0)
	{
		nombre = nombre * -1;
		flags->printed += write(1, "-", 1);
	}
	if (nombre >= len_b)
	{
		ft_putnbr(nombre / len_b, len_b, base, flags);
	}
	reste = nombre % len_b;
	flags->printed += write(1, &base[reste],1);
}

void		ft_putnbr_hex(unsigned long long nbr, t_flags *flags)
{
	unsigned long long	len_b;
	char				*base;
	int					reste;
	
	base = "0123456789abcdef";
	len_b = 16;
	if (nbr >= len_b)
	{
		ft_putnbr_hex(nbr/ len_b, flags);
	}
	reste = nbr % len_b;
	flags->printed += write(1, &base[reste],1);
}

void		ft_putnbr_up_hex(unsigned long long nbr, t_flags *flags)
{
	unsigned long long	len_b;
	char				*base;
	int					reste;
	
	base = "0123456789ABCDEF";
	len_b = 16;
	if (nbr >= len_b)
	{
		ft_putnbr_up_hex(nbr/ len_b, flags);
	}
	reste = nbr % len_b;
	flags->printed += write(1, &base[reste], 1);
}

void		ft_put_un_nbr(unsigned int nb, int len_b, char *base, t_flags *flags)
{
	int		reste;

	if (nb >= (unsigned)len_b)
	{
		ft_put_un_nbr(nb / len_b, len_b, base, flags);
	}
	reste = nb % len_b;
	flags->printed += write(1, &base[reste], 1);
}
