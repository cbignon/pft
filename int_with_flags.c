/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_with_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:52:22 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/26 15:42:02 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	int_with_flags(t_flags *flags, int n)
{
	int	initial_len;
	int	to_add;
	int	add_back;

	initial_len = ft_count_digit(n);
	to_add = 0;
	add_back = 0;
	if (flags->width > 0)
	{
		if (initial_len < flags->width)
			to_add = flags->width - initial_len;
	}
	if (flags->dot)
	{
		if (initial_len < flags->precision)
			add_back = flags->precision - initial_len;
	}
	if (flags->dot && flags->width > 0)
		to_add -= add_back;
	ft_print_int(n, to_add, add_back, flags);
}