/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:50:39 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/25 15:50:23 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->i = 0;
	flags->printed = 0;
}

void	ft_all_flags(t_flags *flags)
{
	flags->precision = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->type = '0';
}
