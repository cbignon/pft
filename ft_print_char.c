/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:30:09 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 22:06:44 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	char_with_flags(t_flags *flags)
{
	int		space;
	char	c;

	if (flags->type == 'c')
		c = va_arg(flags->args, int);
	else
		c = '%';
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
