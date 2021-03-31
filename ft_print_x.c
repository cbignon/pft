/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:21:29 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 17:22:35 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_print_hexa(long int hexa, int to_add, int add_back, t_flags *flags)
{
	if (flags->width > 0 && flags->dot == 0)
		x_only_width(hexa, to_add, flags);
	else if (flags->dot == 1 && flags->width == 0)
		x_only_prec(hexa, add_back, flags);
	else if (flags->dot == 1 && flags->width > 0)
		x_prec_and_width(hexa, to_add, add_back, flags);
	else
	{
		if (flags->type == 'x')
			ft_putnbr_hex((unsigned long long)hexa, flags);
		else
			ft_putnbr_up_hex((unsigned long long)hexa, flags);
	}
}

void	x_only_width(long int hexa, int to_add, t_flags *flags)
{
	if (flags->zero == 1)
	{
		put_zero(to_add, flags);
		if (flags->type == 'x')
			ft_putnbr_hex((unsigned long long)hexa, flags);
		else
			ft_putnbr_up_hex((unsigned long long)hexa, flags);
	}
	else if (flags->minus == 1)
	{
		if (flags->type == 'x')
			ft_putnbr_hex((unsigned long long)hexa, flags);
		else
			ft_putnbr_up_hex((unsigned long long)hexa, flags);
		put_space(to_add, flags);
	}
	else if (flags->minus == 0 && flags->zero == 0)
	{
		put_space(to_add, flags);
		if (flags->type == 'x')
			ft_putnbr_hex((unsigned long long)hexa, flags);
		else
			ft_putnbr_up_hex((unsigned long long)hexa, flags);
	}
}

void	x_only_prec(long int hexa, int to_add, t_flags *flags)
{
	if (hexa == 0 && flags->precision == 0)
		return ;
	put_zero(to_add, flags);
	if (flags->type == 'x')
		ft_putnbr_hex((unsigned long long)hexa, flags);
	else
		ft_putnbr_up_hex((unsigned long long)hexa, flags);
}

void	x_prec_and_width(long int hexa, int add, int add_back, t_flags *flags)
{
	if (hexa == 0 && flags->precision == 0)
	{
		put_space(add, flags);
		flags->printed += write(1, " ", 1);
		return ;
	}
	if (flags->minus)
	{
		put_zero(add_back, flags);
		if (flags->type == 'x')
			ft_putnbr_hex((unsigned long long)hexa, flags);
		else
			ft_putnbr_up_hex((unsigned long long)hexa, flags);
		put_space(add, flags);
	}
	else
	{
		put_space(add, flags);
		put_zero(add_back, flags);
		if (flags->type == 'x')
			ft_putnbr_hex((unsigned long long)hexa, flags);
		else
			ft_putnbr_up_hex((unsigned long long)hexa, flags);
	}
}
