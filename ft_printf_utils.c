/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:54:29 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 17:25:00 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void		ft_pf_putstr(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	if (str[i])
	{
		while (str[i] != '\0')
		{
			flags->printed += write(1, &str[i], 1);
			i++;
		}
	}
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
	flags->printed += write(1, &base[reste], 1);
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
		ft_putnbr_hex(nbr / len_b, flags);
	}
	reste = nbr % len_b;
	flags->printed += write(1, &base[reste], 1);
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
		ft_putnbr_up_hex(nbr / len_b, flags);
	}
	reste = nbr % len_b;
	flags->printed += write(1, &base[reste], 1);
}

void		ft_put_un_nbr(unsigned int n, int len, char *base, t_flags *flags)
{
	int		reste;

	if (n == 4294967295)
	{
		flags->printed += write(1, "4294967295", 10);
		return ;
	}
	if (n >= (unsigned)len)
	{
		ft_put_un_nbr(n / len, len, base, flags);
	}
	reste = n % len;
	flags->printed += write(1, &base[reste], 1);
}
