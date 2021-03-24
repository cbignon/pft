/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:27:06 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/24 20:12:22 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_print_it(int n, int to_add, t_flags *flags)
{
	if (flags->width > 0)
	{
		if (flags->zero == 1)
		{
			if (n >= 0)
			{
				while (to_add > 0)
				{
					flags->printed += write(1, "0", 1);
					to_add--;
				}
			ft_putnbr(n, 10, "0123456789", flags);
			}
			else if (n < 0)
			{
				flags->printed +=  write(1, "-", 1);
				n *= -1;
				while (to_add > 0)
				{
					flags->printed += write(1, "0", 1);
					to_add--;
				}
			ft_putnbr(n, 10, "0123456789", flags);
			}
		}
		else if (flags->minus == 1)
		{
			ft_putnbr(n, 10, "0123456789", flags);
			while ( to_add > 0)
			{
				flags->printed += write(1, " ", 1);
				to_add--;
			}
		}
		else if (flags->minus == 0)
		{
			while ( to_add > 0)
			{
				flags->printed += write(1, " ", 1);
				to_add--;
			}
			ft_putnbr(n, 10, "0123456789", flags);
		}
	}
	else if (flags->dot == 1)
	{
		if (n == 0 && flags->precision == 0)
			return ;
		else if (n < 0)
		{
			flags->printed += write(1, "-",1);
			n *= -1;
			if ((unsigned)to_add > ft_count_digit(n))
				to_add += 1;
			while (to_add > 0)
			{
				flags->printed += write(1, "0", 1);
				to_add--;
			}
			ft_put_un_nbr((unsigned)n, 10, "0123456789", flags);
		}
		else if (n >= 0)
		{
			while (to_add > 0)
			{
				flags->printed += write(1, "0", 1);
				to_add--;
			}
			ft_putnbr(n, 10, "0123456789", flags);
		}
	}
	else
		ft_putnbr(n, 10, "0123456789", flags);
}