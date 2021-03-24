/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:47:38 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/24 10:21:58 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_print_until(const char *format, char c, t_flags *flags)
{
	while (format[flags->i] && format[flags->i] != c)
	{
		flags->printed += write(1, &format[flags->i], 1);
		flags->i++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_flags	flags;

	va_start(flags.args, format);
	ft_init_flags(&flags);
	while (format[flags.i])
	{
		ft_all_flags(&flags);
		ft_print_until(format, '%', &flags);
		if (format[flags.i])
		{
			ft_parse_format(format, &flags);
			convert_with_flags(&flags);
		}
	}
	va_end(flags.args);
	return (flags.printed);
}
