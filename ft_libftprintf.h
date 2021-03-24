/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:48:15 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/24 15:53:08 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...
) __attribute__((format(printf,1,2)));

typedef struct	s_flags
{
	char			type;
	int				i;
	int				zero;
	long long		width;
	int				dot;
	long long		precision;
	int				minus;
	int				printed;
	va_list			args;
}				t_flags;
int				ft_printf(const char *format, ...);
void			ft_print_until(const char *format, char c, t_flags *flags);
void			ft_parse_format(const char *fmt, t_flags *flags);
void			ft_get_precision(const char *format, t_flags *flags);
void			ft_get_width(const char *fmt, t_flags *flags);
void			treat_minus(const char *fmt, t_flags *flags);
size_t			ft_strlen(const char *str);
int				ft_putstr(char *str);
void			ft_putnbr_hex(unsigned long long nbr, t_flags *flags);
void			ft_putnbr_up_hex(unsigned long long nbr, t_flags *flags);
void			ft_putnbr(int nb, int len_b, char *base, t_flags *flags);
unsigned int	ft_count_digit(int n);
unsigned int	ft_count_hexa(unsigned long long n);
void			ft_put_un_nbr(unsigned int nb, int len_b, char *base, t_flags *flags);
void			ft_convert_char(t_flags *flags);
void			ft_convert_str(t_flags *flags);
void			ft_convert_address(t_flags *flags);
void			ft_convert_int_sign(t_flags *flags);
void			ft_convert_u_int(t_flags *flags);
void			ft_convert_hex(t_flags *flags);
void			ft_convert_up_hex(t_flags *flags);
void			ft_convert_pct(t_flags *flags);
int				ft_is_flag(char c);
int				ft_is_num(char c);
char			ft_is_type(char c);
int				ft_is_in_flags(char c);
void			ft_init_flags(t_flags *flags);
void			ft_all_flags(t_flags *flags);
void			ft_dot(const char *format, t_flags *flags);
void			convert_int_with_dot(t_flags *flags,int n);
void			convert_int_with_width(t_flags *flags, int n);
void			convert_int_space_after(t_flags *flags, int n);
void			convert_uint_with_dot(t_flags *flags,unsigned int n);
void			convert_uint_with_width(t_flags *flags, unsigned int n);
void			convert_uint_space_after(t_flags *flags, unsigned int n);
void			convert_str_with_dot(t_flags *flags, char *str);
void			ft_star(const char *format, t_flags *flags);
void			ft_width(const char *format, t_flags *flags);
void			ft_zero(const char *format,t_flags *flags);
void			convert_str_with_zero(t_flags *flags, char *str);
void			convert_with_flags(t_flags *flags);
void			int_with_flags(t_flags *flags, int n);
void			ft_print_it(int n, int to_add, t_flags *flags);
#endif
