#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_libftprintf.h"

int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	
	ft_printf(" --- Return 15 : %d\n", ft_printf("%-0i, %-0d, %-0d, %-0i, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d));//T15
	ft_printf(" --- Return 16 : %d\n", ft_printf("%0-i, %0-d, %0-d, %0-i, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	ft_printf(" --- Return 31 : %d\n", ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
	printf(" --- Return 15o : %d\n", printf("%-0i, %-0d, %-0d, %-0d, %-0i, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d));//T15
	printf(" --- Return 16o : %d\n", printf("%0-i, %0-d, %0-d, %0-d, %0-i, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	printf(" --- Return 31o : %d\n", printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
}