/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:46:28 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/29 14:54:38 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_convert_address(t_flags *flags)
{
	unsigned long long	address;
	
	address = (unsigned long long)va_arg(flags->args, void*);
	if (address == 0)
	{
		flags->printed += write(1, "0x0", 3);
		return;
	}
	flags->printed += write(1, "0x", 2);
	ft_putnbr_hex(address, flags);
}

void	ft_convert_hex(t_flags *flags)
{
	unsigned	hexa;

	hexa = va_arg(flags->args, unsigned);
	ft_putnbr_hex((unsigned long long)hexa, flags);
}

void	ft_convert_up_hex(t_flags *flags)
{
	unsigned	hexa;

	hexa = va_arg(flags->args, unsigned);
	ft_putnbr_up_hex((unsigned long long)hexa, flags);
}
