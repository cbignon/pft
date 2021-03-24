/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_with_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:31:33 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/24 10:26:50 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	convert_with_flags(t_flags *flags)
{
	int	n;

	if (flags->type == 'd' || flags->type == 'i')
	{
		n = va_arg(flags->args, int);
		int_with_flags(flags, n);
	}
}