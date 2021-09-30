/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:58:23 by cbignon           #+#    #+#             */
/*   Updated: 2021/04/12 15:55:31 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ptr_with_flags(t_flags *flags)
{
	unsigned long long	address;
	int					len;
	int					space;

	space = 0;
	address = va_arg(flags->args, unsigned long long);
	len = ft_count_hexa(address) + 2;
	if (address == 0 && flags->dot && flags->precision == 0)
		len -= 1;
	if (flags->width > len)
		space = flags->width - len;
	ft_convert_address(flags, address, space);
}

void	ft_convert_address(t_flags *flags, unsigned long long adrs, int space)
{
	if (flags->minus)
	{
		flags->printed += write(1, "0x", 2);
		if (!(adrs == 0 && flags->dot == 1 && flags->precision == 0))
			ft_putnbr_hex(adrs, flags);
	}
	put_space(space, flags);
	if (!flags->minus)
	{
		flags->printed += write(1, "0x", 2);
		if (!(adrs == 0 && flags->dot == 1 && flags->precision == 0))
			ft_putnbr_hex(adrs, flags);
	}
}
