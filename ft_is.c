/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:31:56 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/24 10:11:16 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'p' || c == 'u' 
	|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

int ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_is_flag(char c)
{
	if (c == '.' || c == '*' || c == '-' || c == '0')
		return (1);
	return (0);
}

int	ft_is_in_flags(char c)
{
	if (c == '.' || c == '*' || c == '-' || c == '0' || c == 'c' || c == 's'
	|| c == 'd' || c == 'i' || c == 'p' || c == 'u' || c == 'x' || c == 'X'
	|| c == '%' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
