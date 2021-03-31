/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:09:21 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 19:20:35 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_print_u_int(unsigned int n, int to_add, int add_back, t_flags *flags)
{
	if (flags->width > 0 && flags->dot == 0)
		u_only_width(n, to_add, flags);
	else if (flags->dot == 1 && flags->width == 0)
		u_only_prec(n, add_back, flags);
	else if (flags->dot == 1 && flags->width > 0)
		u_prec_width(n, to_add, add_back, flags);
	else
		ft_put_un_nbr(n, 10, "0123456789", flags);
}

void	u_only_width(unsigned int n, int to_add, t_flags *flags)
{
	if (flags->zero == 1)
	{
		put_zero(to_add, flags);
		ft_put_un_nbr(n, 10, "0123456789", flags);
	}
	else if (flags->minus == 1)
	{
		ft_put_un_nbr(n, 10, "0123456789", flags);
		put_space(to_add, flags);
	}
	else if (flags->minus == 0 && flags->zero == 0)
	{
		put_space(to_add, flags);
		ft_put_un_nbr(n, 10, "0123456789", flags);
	}
}

void	u_only_prec(int n, int to_add, t_flags *flags)
{
	if (n == 0 && flags->precision == 0)
		return ;
	put_zero(to_add, flags);
	ft_put_un_nbr(n, 10, "0123456789", flags);
}

void	u_prec_width(unsigned n, int add, int add_b, t_flags *flags)
{
	if (n == 0)
	{
		deal_zero_int(add, add_b, flags);
		return ;
	}
	if (flags->minus)
	{
		put_zero(add_b, flags);
		ft_put_un_nbr(n, 10, "0123456789", flags);
		put_space(add, flags);
	}
	else
	{
		put_space(add, flags);
		put_zero(add_b, flags);
		ft_put_un_nbr(n, 10, "0123456789", flags);
	}
}
