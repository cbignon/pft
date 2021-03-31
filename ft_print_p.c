/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:58:23 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 12:30:36 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ptr_with_flags(t_flags *flags)
{
	unsigned long long	address;
	int					len;
	int					space;

	space = 0;
	address = (unsigned long long)va_arg(flags->args, void*);
	len = ft_count_hexa(address);
	if (address == 0)
		len += 2;
	else
		len += 2;
	if (flags->width > len)
		space = flags->width - len;
	ft_convert_address(flags, address, space);
}

void	ft_convert_address(t_flags *flags, unsigned long long address, int space)
{
	if (flags->width)
	{
		if (flags->minus == 1)
		{
			if (address == 0)
				flags->printed += write(1, "0x0", 3);
			else
			{
				flags->printed += write(1, "0x", 2);
				ft_putnbr_hex(address, flags);
			}
		}
		put_space(space, flags);
	}
	if (flags->minus == 0)
	{
		if (address == 0)
			flags->printed += write(1, "0x0", 3);
		else
		{
			flags->printed += write(1, "0x", 2);
			ft_putnbr_hex(address, flags);
		}
	}
}
