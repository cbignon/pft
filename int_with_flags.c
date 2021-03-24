/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_with_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:52:22 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/24 11:17:01 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	int_with_flags(t_flags *flags,int n)
{
	int	initial_len;
	int	to_add;

	initial_len = ft_count_digit(n);
	to_add = 0;
	if (flags->width > 0)
	{
		if (initial_len >= flags->width)
			to_add = 0;
		else if (initial_len < flags->width)
			to_add = flags->width - initial_len;
	}
	if (flags->dot == 1)
	{
		if (initial_len >= flags->precision)
			to_add = 0;
		else if (initial_len < flags->precision)
			to_add = flags->precision - initial_len;
	}
	ft_print_it(n, to_add, flags);
}