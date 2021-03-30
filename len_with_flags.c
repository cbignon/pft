/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_with_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:52:22 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/30 21:39:02 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	int_with_flags(t_flags *flags, long int n)
{
	int	initial_len;
	int	to_add;
	int	add_back;

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

void	str_with_flags(t_flags *flags, char *s)
{
	int	initial_len;
	int	max_len;
	int	space;

	if (s == NULL)
		initial_len = 6;
	else
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

void	char_with_flags(t_flags *flags, char c)
{
	int	space;

	space = 0;
	if (flags->width >= 1)
		space = flags->width - 1;
	if (flags->type == '%' && flags->zero)
		put_zero(space, flags);
	else if (flags->minus == 0)
		put_space(space, flags);
	flags->printed += write(1, &c, 1);
	if (flags->minus == 1)
		put_space(space, flags);
}
