/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uint_with_flags.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:14:51 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/17 15:19:14 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	convert_uint_with_dot(t_flags *flags, unsigned int n)
{
	int	count;
	int	zero;

	count = ft_count_digit(n);
	if (flags->precision == 0 && n == 0)
		return;
	if (flags->precision > count)
	{
		zero = (flags->precision - count);
		if (n >= 0)
		{
			while (zero-- > 0)
				flags->printed += write(1, "0", 1);
			ft_putnbr(n, 10, "0123456789", flags);
		}
		while (zero-- > 0)
			flags->printed += write(1, "0", 1);
		ft_put_un_nbr(n, 10, "0123456789", flags);
	}
	else
		ft_putnbr(n, 10, "0123456789", flags);
}

void	convert_uint_with_width(t_flags *flags, unsigned int n)
{
	int	count;
	int	space;

	count = ft_count_digit(n);
	if (flags->width == 0 && n == 0)
	{
		flags->printed += write(1, " ", 1);
		return;
	}
	if (flags->width > count)
	{
		space = (flags->width - count);
		while (space > 0)
		{
			flags->printed += write(1, " ", 1);
			space--;
		}
		ft_put_un_nbr(n, 10, "0123456789", flags);
	}
	else
		ft_put_un_nbr(n, 10, "0123456789", flags);
}

void	convert_uint_space_after(t_flags *flags, unsigned int n)
{
	int	count;
	int	space;

	count = ft_count_digit(n);
	if (flags->width == 0 && n == 0)
	{
		flags->printed += write(1, "0", 1);
		return;
	}
	if (flags->width > count)
	{
		space = flags->width - count;
		ft_put_un_nbr(n, 10, "0123456789", flags);
		while (space > 0)
		{
			flags->printed += write(1, " ", 1);
			space--;
		}
	}
	else
		ft_put_un_nbr(n, 10, "0123456789", flags);
}