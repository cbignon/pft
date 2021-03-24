/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:46:28 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/23 15:02:51 by cbignon          ###   ########.fr       */
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

void	ft_convert_int_sign(t_flags *flags)
{
	int	nb;

	nb = va_arg(flags->args, int);
	if (flags->dot == 1)
		convert_int_with_dot(flags, nb);
	else if (flags->width > 0 && flags->minus == 0)
		convert_int_with_width(flags, nb);
	else if(flags->width > 0 && flags->minus == 1)
		convert_int_space_after(flags, nb);
	else
		ft_putnbr(nb, 10, "0123456789", flags);
}

void	ft_convert_u_int(t_flags *flags)
{
	unsigned int	nb;

	nb = va_arg(flags->args, unsigned int);
	if (flags->dot == 1)
		convert_int_with_dot(flags, nb);
	else if (flags->width > 0 && flags->minus == 0)
		convert_int_with_width(flags, nb);
	else if(flags->width > 0 && flags->minus == 1)
		convert_int_space_after(flags, nb);
	else
		ft_put_un_nbr(nb, 10, "0123456789", flags);
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
