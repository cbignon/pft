/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:49:47 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 19:21:30 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_print_str(char *s, int max_len, int space, t_flags *flags)
{
	if (s == NULL)
		s = "(null)";
	if (flags->width > 0 && flags->dot == 0)
		s_only_width(s, space, flags);
	else if (flags->dot == 1 && flags->width == 0)
		s_only_prec(s, max_len, flags);
	else if (flags->dot == 1 && flags->width > 0)
	{
		if (flags->precision == 0)
			put_space(flags->width, flags);
		else
			s_prec_width(s, max_len, space, flags);
	}
	else
		ft_pf_putstr(s, flags);
}

void	s_only_width(char *s, int space, t_flags *flags)
{
	int	initial_len;

	initial_len = ft_strlen(s);
	if (flags->width <= initial_len)
		ft_pf_putstr(s, flags);
	if (flags->width > initial_len && flags->minus == 0)
	{
		put_space(space, flags);
		ft_pf_putstr(s, flags);
	}
	else if (flags->width > initial_len && flags->minus)
	{
		ft_pf_putstr(s, flags);
		put_space(space, flags);
	}
}

void	s_only_prec(char *s, int max_len, t_flags *flags)
{
	if (flags->precision <= 0)
		return ;
	print_len(s, max_len, flags);
}

void	s_prec_width(char *s, int max_len, int space, t_flags *flags)
{
	int	initial_len;

	initial_len = ft_strlen(s);
	if (flags->precision > initial_len && flags->width > initial_len)
	{
		if (flags->minus)
		{
			ft_pf_putstr(s, flags);
			put_space(space, flags);
			return ;
		}
		put_space(space, flags);
		ft_pf_putstr(s, flags);
	}
	else if (flags->precision <= initial_len)
	{
		if (flags->minus)
			print_len(s, max_len, flags);
		put_space(space, flags);
		if (flags->minus == 0)
			print_len(s, max_len, flags);
	}
	else if (flags->width < flags->precision)
		ft_pf_putstr(s, flags);
}
