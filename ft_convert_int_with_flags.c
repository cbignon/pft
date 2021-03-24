/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_with_flags.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:10:34 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/23 15:08:44 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	convert_int_with_dot(t_flags *flags, int n)
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
		if (n < 0)
		{
			n = n * -1;
			zero = flags->precision - ft_count_digit(n);
			flags->printed += write(1, "-", 1);
			while (zero > 0)
			{
				flags->printed += write(1, "0", 1);
				zero--;
			}
			ft_putnbr(n, 10, "0123456789", flags);
		}
	}
	else
		ft_putnbr(n, 10, "0123456789", flags);
}

void	convert_int_with_width(t_flags *flags, int n)
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
		if(flags->zero == 0)
		{
			while (space > 0)
			{
				flags->printed += write(1, " ", 1);
				space--;
			}
		}
		else
			while (space > 0)
			{
				flags->printed += write(1, "0", 1);
				space--;
			}
		ft_putnbr(n, 10, "0123456789", flags);
	}
	else
		ft_putnbr(n, 10, "0123456789", flags);
}

void	convert_int_space_after(t_flags *flags, int n)
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
		if (n < 0)
		{
			flags->printed += write(1, "-", 1);
			space--;
		}
		ft_putnbr(n, 10, "0123456789", flags);
		if (flags->zero == 0)
		{
			while (space > 0)
			{
				flags->printed += write(1, " ", 1);
				space--;
			}
		}
		else
		{
			while (space > 0)
			{
				flags->printed += write(1, "0", 1);
				space--;
			}
		}
	}
	else
		ft_putnbr(n, 10, "0123456789", flags);
}
