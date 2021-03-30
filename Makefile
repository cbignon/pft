# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 11:17:28 by cbignon           #+#    #+#              #
#    Updated: 2021/03/30 10:54:09 by cbignon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SOURCES=	ft_printf.c \
			ft_parse_format.c \
			ft_printf_utils.c \
			ft_utils_count.c \
			ft_convert_type.c \
			ft_is.c \
			ft_flags.c \
			len_with_flags.c \
			convert_with_flags.c \
			ft_print_int.c \
			ft_print_s.c\

CC= clang

CFLAGS= -Wall -Werror -Wextra

.c.o : 
	$(CC) $(CFLAGS) -c $<

OBJETS= $(SOURCES:.c=.o)

$(NAME) : $(OBJETS)
	ar -rcs $(NAME) $(OBJETS)

all : $(NAME)

clean :
	rm -f $(OBJETS)

fclean : clean
	rm -f $(NAME)

re : fclean all

main.o : main.c
	$(CC) -g3 -o "$@" -c "$<"
	
main : main.o $(NAME)
	$(CC) main.o -o main.out -L . -l ftprintf
