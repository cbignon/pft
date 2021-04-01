/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:28:50 by cbignon           #+#    #+#             */
/*   Updated: 2021/04/01 12:36:52 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_parse_format(const char *fmt, t_flags *flags)
{
	flags->i++;
	while (ft_is_in_flags(fmt[flags->i]))
	{
		if (fmt[flags->i] == '-')
			treat_minus(fmt, flags);
		if (ft_is_num(fmt[flags->i]) || fmt[flags->i] == '*')
			ft_get_width(fmt, flags);
		if (fmt[flags->i] == '.')
			ft_get_precision(fmt, flags);
		if (ft_is_type(fmt[flags->i]))
		{
			flags->type = fmt[flags->i];
			flags->i++;
			if (flags->minus == 1 && flags->zero == 1)
				flags->zero = 0;
			return ;
		}
	}
}

void	ft_get_precision(const char *fmt, t_flags *flags)
{
	flags->i++;
	flags->dot = 1;
	while (ft_is_num(fmt[flags->i]))
	{
		flags->precision = (flags->precision * 10) + (fmt[flags->i] - '0');
		flags->i++;
	}
	if (fmt[flags->i] == '*')
	{
		flags->precision = va_arg(flags->args, int);
		flags->i++;
	}
	if (flags->precision < 0)
	{
		flags->precision = 0;
		flags->dot = 0;
	}
}

void	ft_get_width(const char *fmt, t_flags *flags)
{
	if (fmt[flags->i] == '0')
	{
		flags->zero = 1;
		flags->i++;
	}
	if (fmt[flags->i] == '-')
		treat_minus(fmt, flags);
	while (ft_is_num(fmt[flags->i]))
	{
		flags->width = (flags->width * 10) + (fmt[flags->i] - '0');
		flags->i++;
	}
	if (fmt[flags->i] == '*')
	{
		flags->width = va_arg(flags->args, int);
		flags->i++;
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->minus = 1;
		}
	}
}

void	treat_minus(const char *fmt, t_flags *flags)
{
	if (fmt[flags->i] == '-')
	{
		flags->minus = 1;
		flags->i++;
	}
}
