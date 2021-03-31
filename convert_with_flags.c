/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_with_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:31:33 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 16:38:42 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	convert_with_flags(t_flags *flags)
{
	if (flags->type == 'd' || flags->type == 'i')
		int_with_flags(flags);
	if (flags->type == 'u')
		u_int_with_flags(flags);
	if (flags->type == 'c' || flags->type == '%')
		char_with_flags(flags);
	if (flags->type == 'x' || flags->type == 'X')
		hexa_with_flags(flags);
	if (flags->type == 'p')
		ptr_with_flags(flags);
	if (flags->type == 's')
		str_with_flags(flags);
}

void	put_zero(int to_add, t_flags *flags)
{
	while (to_add > 0)
	{
		flags->printed += write(1, "0", 1);
		to_add--;
	}
}

void	put_space(int to_add, t_flags *flags)
{
	while (to_add > 0)
	{
		flags->printed += write(1, " ", 1);
		to_add--;
	}
}
