/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str_with_dot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:59:28 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/17 14:47:01 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	convert_str_with_dot(t_flags *flags, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (convert_str_with_dot(flags,"(null)"));
	if ((int)ft_strlen(str) <= flags->precision)
		flags->printed += ft_putstr(str);
	else
		while (i < flags->precision)
		{
			flags->printed += write(1, &str[i], 1);
			i++;
		}
	flags->i++;
}
