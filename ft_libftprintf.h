/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:48:15 by cbignon           #+#    #+#             */
/*   Updated: 2021/03/31 14:05:23 by cbignon          ###   ########.fr       */
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
void			ft_pf_putstr(char *str, t_flags *flags);
void			ft_putnbr_hex(unsigned long long nbr, t_flags *flags);
void			ft_putnbr_up_hex(unsigned long long nbr, t_flags *flags);
void			ft_putnbr(int nb, int len_b, char *base, t_flags *flags);
unsigned int	ft_count_digit(long int n);
unsigned int	ft_count_hexa(unsigned long long n);
void			ft_put_un_nbr(unsigned int nb, int len_b, char *base, t_flags *flags);
void			ft_convert_char(t_flags *flags);
void			ft_convert_str(t_flags *flags);
void			ft_convert_address(t_flags *flags, unsigned long long address, int space);
void			ft_convert_int_sign(t_flags *flags);
void			ft_convert_u_int(t_flags *flags);
void			ft_convert_hex(t_flags *flags, unsigned hexa);
void			ft_convert_up_hex(t_flags *flags, unsigned hexa);
//void			ft_convert_pct(t_flags *flags);
int				ft_is_flag(char c);
int				ft_is_num(char c);
char			ft_is_type(char c);
int				ft_is_in_flags(char c);
void			ft_init_flags(t_flags *flags);
void			ft_all_flags(t_flags *flags);
void			ft_dot(const char *format, t_flags *flags);
void			ft_star(const char *format, t_flags *flags);
void			ft_width(const char *format, t_flags *flags);
void			ft_zero(const char *format,t_flags *flags);
void			convert_with_flags(t_flags *flags);
void			int_with_flags(t_flags *flags);
void			u_int_with_flags(t_flags *flags);
void			ft_print_u_int(unsigned int n, int to_add, int add_back, t_flags *flags);
void			ft_print_int(long int n, int to_add, int add_back, t_flags *flags);
void			put_zero(int to_add, t_flags *flags);
void			put_space(int to_add, t_flags *flags);
void			u_only_prec(int n, int to_add, t_flags *flags);
void			u_only_width(unsigned int n, int to_add, t_flags *flags);
void			u_prec_and_width(unsigned int n, int to_add, int add_back, t_flags *flags);
void			only_width(int n, int to_add, t_flags *flags);
void			only_prec(int n, int to_add, t_flags *flags);
void			prec_and_width(int n, int to_add, int add_back, t_flags *flags);
void			deal_neg_int(int n, int to_add, int add_back, t_flags *flags);
void			deal_zero_int(int to_add, int add_back, t_flags *flags);
void			ft_print_char(char *s, int max_len, int space, t_flags *flags);
void			print_len(char *s, int	len, t_flags *flags);
void			s_only_width(char *s, int space, t_flags *flags);
void			s_only_prec(char *s, int max_len, t_flags *flags);
void			s_prec_and_width(char *s, int max_len, int space, t_flags *flags);
void			str_with_flags(t_flags *flags);
void			ft_print_str(char *s, int max_len, int space, t_flags *flags);
void			char_with_flags(t_flags *flags);
void			hexa_with_flags(t_flags *flags);
void			ft_print_hexa(long int hexa, int to_add, int add_back, t_flags *flags);
void			ptr_with_flags(t_flags *flags);
void			x_prec_and_width(long int hexa, int to_add, int add_back, t_flags *flags);
void			x_only_prec(long int hexa, int to_add, t_flags *flags);
void			x_only_width(long int hexa, int to_add, t_flags *flags);
#endif
