/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:49:47 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/30 16:00:07 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_print_str(char *s, int max_len, int space, t_flags *flags)
{
	if (flags->width > 0 && flags->dot == 0)
		s_only_width(s, space, flags);
	else if (flags->dot == 1 && flags->width == 0)
		s_only_prec(s, max_len, flags);
	else if (flags->dot == 1 && flags->width > 0)
		s_prec_and_width(s, max_len, space, flags);
	else
		ft_pf_putstr(s, flags);
}

void	print_len(char *s, int len, t_flags *flags)
{
	int	i;

	i = 0;
	while (len)
	{
		flags->printed += write(1, &s[i], 1);
		i++;
		len--;
	}
}

void	s_only_width(char *s, int space, t_flags *flags)
{
	int	initial_len;

	initial_len = 6;
	if (s == NULL)
		s = "(null)";
	if (s)
	{
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
}

void	s_only_prec(char *s, int max_len, t_flags *flags)
{

	if ( flags->precision <= 0)
		return ;
	if (s == NULL)
		s = "(null)";
	if (s)
		print_len(s, max_len, flags);
}

void	s_prec_and_width(char *s, int max_len, int space, t_flags *flags)
{
	int	initial_len;
	int	i;

	initial_len = ft_strlen(s);
	i = 0;
	if (s == NULL)
		s = "(null)";
	if (s)
	{
		if (flags->precision == 0)
			put_space(flags->width, flags);
		else if (flags->precision > initial_len && flags->width > initial_len)
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
}