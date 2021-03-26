/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:47:53 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/26 20:43:06 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_convert_char(t_flags *flags)
{
	char	to_print;

	to_print = (char)va_arg(flags->args, int);
	flags->printed += write(1, &to_print, 1);
}

void	ft_convert_str(t_flags *flags)
{
	char	*to_print;

	to_print = va_arg(flags->args, char*);
	if (flags->dot == 1)
		convert_str_with_dot(flags, to_print);
	else if (flags->precision > 0)
		convert_str_width(flags, to_print);
	else
		flags->printed += ft_putstr(to_print);
}

void	ft_convert_pct(t_flags *flags)
{
	char	pct;

	pct = '%';
	flags->printed += write(1, &pct, 1);
}
