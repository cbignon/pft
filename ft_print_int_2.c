/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:52:52 by cbignon           #+#    #+#             */
/*   Updated: 2021/04/08 14:32:18 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	deal_neg_int(int n, int to_add, int add_back, t_flags *flags)
{
	int			len;
	long int	nb;

	nb = n * -1;
	len = (int)ft_count_digit(n);
	if (flags->minus)
	{
		flags->printed += write(1, "-", 1);
		put_zero(add_back + 1, flags);
		ft_put_un_nbr(nb, 10, "0123456789", flags);
		put_space(to_add, flags);
	}
	else
	{
		put_space(to_add, flags);
		flags->printed += write(1, "-", 1);
		put_zero(add_back + 1, flags);
		ft_put_un_nbr(nb, 10, "0123456789", flags);
	}
}

void	deal_zero_int(int to_add, int add_back, t_flags *flags)
{
	if (flags->dot && flags->precision == 0)
	{
		flags->printed += write(1, " ", 1);
		put_space(to_add, flags);
	}
	else
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
