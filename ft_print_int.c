/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:42:56 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/26 17:39:15 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_print_int(int n, int to_add, int add_back, t_flags *flags)
{
	if (flags->width > 0 && flags->dot == 0)
		only_width(n, to_add, flags);
	else if (flags->dot == 1 && flags->width == 0)
		only_prec(n, add_back, flags);
	else if (flags->dot == 1 && flags->width > 0
	&& flags->width != flags->precision)
		prec_and_width(n, to_add, add_back, flags);
	else
		ft_putnbr(n, 10, "0123456789", flags);
}

void	put_zero(int to_add, t_flags *flags)
{
	while (to_add > 0)
	{
		flags->printed += write(1, "0", 1);
		to_add--;
	}
}

void	put_space(int to_add, t_flags *flags)
{
	while (to_add > 0)
	{
		flags->printed += write(1, " ", 1);
		to_add--;
	}
}

void	only_width(int n, int to_add, t_flags *flags)
{
	if (flags->zero == 1)
	{
		if (n >= 0)
		{
			put_zero(to_add, flags);
			ft_putnbr(n, 10, "0123456789", flags);
		}
		else if (n < 0)
		{
			flags->printed += write(1, "-",1);
			n *= -1;
			put_zero(to_add, flags);
			ft_put_un_nbr((unsigned)n, 10, "0123456789", flags);
		}
	}
	else if (flags->minus == 1)
	{
		ft_putnbr(n, 10, "0123456789", flags);
		put_space(to_add, flags);
	}
	else if (flags->minus == 0 && flags->zero == 0)
	{
		put_space(to_add, flags);
		ft_putnbr(n, 10, "0123456789", flags);
	}
}

void	only_prec(int n, int to_add, t_flags *flags)
{
	if (n == 0 && flags->precision == 0)
		return ;
	else
	{
		if (n < 0)
		{
			flags->printed += write(1, "-",1);
			n *= -1;
			if (flags->precision > ft_count_digit(n))
				to_add += 1;
			put_zero(to_add, flags);
			ft_put_un_nbr(n, 10, "0123456789", flags);
		}
		else if (n >= 0)
		{
			put_zero(to_add, flags);
			ft_putnbr(n, 10, "0123456789", flags);
		}
	}
}

void	prec_and_width(int n, int to_add, int add_back, t_flags *flags)
{
	if (n > 0)
	{
		if (flags->width > flags->precision)
		{
			if (flags->minus)
			{
				put_zero(add_back, flags);
				ft_putnbr(n, 10, "0123456789", flags);
				put_space(to_add, flags);
			}
			else
			{
				put_space(to_add, flags);
				put_zero(add_back, flags);
				ft_putnbr(n, 10, "0123456789", flags);
			}
		}
		else if (flags->width < flags->precision)
		{
			put_zero(add_back, flags);
			ft_putnbr(n, 10, "0123456789", flags);
			put_space(to_add, flags);
		}
	}
	else if (n < 0)
		deal_neg_int(n, to_add, add_back, flags);
	else if (n == 0)
	{
		if (flags->precision == 0)
		{
			flags->printed += write(1, " ", 1);
			put_space(to_add, flags);
		}
		else if (flags->width > flags->precision)
		{
			if (flags->minus)
			{
				put_zero(add_back, flags);
				flags->printed += write(1, "0", 1);
				put_space(to_add, flags);
			}
			else
			{
				put_space(to_add, flags);
				flags->printed += write(1, "0", 1);
				put_zero(add_back, flags);
			}
		}
	}
}

void	deal_neg_int(int n, int to_add, int add_back, t_flags *flags)
{
	int	len;
	long int	nb;

	len = (int)ft_count_digit(n);
	nb = n * -1;
	if (flags->width > len && flags->precision > len)
	{
		to_add -= 1;
		add_back += 1;
	}
	else if (flags->width < len && flags->precision > len)
		add_back += 1;
	if (flags->width > flags->precision)
	{
		if (flags->minus)
		{
			flags->printed += write(1, "-", 1);
			put_zero(add_back, flags);
			ft_put_un_nbr(nb, 10, "0123456789", flags);
			put_space(to_add, flags);
		}
		else
		{
			put_space(to_add, flags);
			flags->printed += write(1, "-", 1);
			put_zero(add_back, flags);
			ft_put_un_nbr(nb, 10, "0123456789", flags);
		}
	}
	else if (flags->width < flags->precision)
	{
		flags->printed += write(1, "-", 1);
		put_zero(add_back, flags);
		ft_put_un_nbr(nb, 10, "0123456789", flags);
		put_space(to_add, flags);
	}
}