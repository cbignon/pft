/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_with_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:52:22 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 17:31:56 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	int_with_flags(t_flags *flags)
{
	long int	n;
	int			initial_len;
	int			to_add;
	int			add_back;

	n = va_arg(flags->args, int);
	initial_len = ft_count_digit(n);
	to_add = 0;
	add_back = 0;
	if (n < 0)
		initial_len -= 1;
	if (initial_len < flags->width)
		to_add = flags->width - initial_len;
	if (initial_len < flags->precision)
		add_back = flags->precision - initial_len;
	if (flags->dot && flags->width > 0)
		to_add -= add_back;
	if (n < 0)
	{
		add_back -= 1;
		to_add -= 1;
	}
	ft_print_int(n, to_add, add_back, flags);
}

void	hexa_with_flags(t_flags *flags)
{
	unsigned int	n;
	int				initial_len;
	int				to_add;
	int				add_back;

	n = (unsigned)va_arg(flags->args, unsigned);
	initial_len = ft_count_hexa(n);
	to_add = 0;
	add_back = 0;
	if (initial_len < flags->width)
		to_add = flags->width - initial_len;
	if (initial_len < flags->precision)
		add_back = flags->precision - initial_len;
	if (flags->dot && flags->width > 0)
		to_add -= add_back;
	ft_print_hexa(n, to_add, add_back, flags);
}

void	u_int_with_flags(t_flags *flags)
{
	unsigned int	n;
	int				initial_len;
	int				to_add;
	int				add_back;

	n = (unsigned)va_arg(flags->args, unsigned);
	initial_len = ft_count_digit(n);
	to_add = 0;
	add_back = 0;
	if (initial_len < flags->width)
		to_add = flags->width - initial_len;
	if (initial_len < flags->precision)
		add_back = flags->precision - initial_len;
	if (flags->dot && flags->width > 0)
		to_add -= add_back;
	ft_print_u_int(n, to_add, add_back, flags);
}

void	str_with_flags(t_flags *flags)
{
	int		initial_len;
	int		max_len;
	int		space;
	char	*s;

	s = va_arg(flags->args, char*);
	if (s == NULL)
		s = "(null)";
	initial_len = ft_strlen(s);
	max_len = 0;
	space = 0;
	if (flags->width < initial_len)
		max_len = flags->width;
	else if (flags->width >= initial_len)
	{
		space = flags->width - initial_len;
		max_len = initial_len;
	}
	if (flags->dot && flags->precision < initial_len)
		max_len = flags->precision;
	else if (flags->dot && flags->precision >= initial_len)
		max_len = initial_len;
	if (flags->dot && flags->precision)
		space = flags->width - max_len;
	ft_print_str(s, max_len, space, flags);
}
