/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_with_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:31:33 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/26 18:04:55 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	convert_with_flags(t_flags *flags)
{
	int		n;
	char	c;

	if (flags->type == 'd' || flags->type == 'i' || flags->type == 'u')
	{
		if (flags->type == 'u')
			n = (unsigned)va_arg(flags->args, unsigned);
		else
			n = va_arg(flags->args, int);
		int_with_flags(flags, n);
	}
	if (flags->type == 'c' || flags->type == '%')
	{
		if (flags->type == 'c')
			c = va_arg(flags->args, int);
		else
			c = '%';
		flags->printed += write( 1, &c, 1);
	}
	if (flags->type == 'p')
		ft_convert_address(flags);
	if (flags->type == 'x')
		ft_convert_hex(flags);
	if (flags->type == 'X')
		ft_convert_up_hex(flags);
	if (flags->type == 's')
		ft_convert_str(flags);
}