#include "ft_printf.h"
#include <stdio.h>
int main()
{
	ft_printf("%d\n", -12345678);
	printf("%d\n", -12345678);
	ft_printf("%*.*d\n", 10, 9, 2);
	printf("%*.*d\n", 10, 9, 2);
	ft_printf("%10.4s\n", "abc");
	printf("%10.4s\n", "abc");
	ft_printf("%10.2s\n", "abc");
	printf("%10.2s\n", "abc");
	ft_printf("%10.*s\n", 5,"abc");
	printf("%10.*s\n", 5,"abc");
	ft_printf("%10.*d\n", -5,"abc");
	printf("%10.*d\n", -5,"abc");
	ft_printf("%010.*d\n", -5, 10);
	printf("%010.*d\n", -5, 10);
	ft_printf("%-10.*s\n", -5,"abc");
	printf("%-10.*s\n", -5,"abc");
	ft_printf("%-010.*d\n", 5, 10);
	printf("%-010.*d\n", 5, 10);
	ft_printf("%010.5d\n", 2500);
	printf("%010.5d\n", 2500);
	ft_printf("%10.2d\n", -2500);
	printf("%10.2d\n", -2500);
	ft_printf("%10.3d\n", -2500);
	printf("%10.3d\n", -2500);
	ft_printf("%10.4d\n", -2500);
	printf("%10.4d\n", -2500);
	ft_printf("%10.6d\n", -2500);
	printf("%10.6d\n", -2500);
	ft_printf("%-*d\n", -5, 6);
	printf("%-*d\n", -5, 6);
	ft_printf("%2.0d\n", 0);
	printf("%2.0d\n", 0);
	ft_printf("%-12.5d\n",-456);
	printf("%-12.5d\n", -456);
	ft_printf("%2.*d\n", -5, 4);
	printf("%2.*d\n", -5, 4);
	ft_printf("%05.*d\n", -5, 0);
	printf("%05.*d\n", -5, 0);
	ft_printf("%0*d\n", 5, 5);
	printf("%0*d\n", 5, 5);
	ft_printf("%0*d\n", -5, 5);
	printf("%0*d\n", -5, 5);
	ft_printf("%0*.*d\n", -5, 5, 0);
	printf("%0*.*d\n", -5, 5, 0);
	ft_printf("%0*.2d\n", -5, 0);
	printf("%0*.2d\n", -5, 0);
	ft_printf("%0.d\n", 0);
	printf("%0.d\n", 0);
	ft_printf("%1.dg\n", 0);
	printf("%1.dg\n", 0);
	printf("%1.dg\n", 0);
	ft_printf("%.4s\n", "csbbh");
	printf("%.4s\n", "csbbh");
	ft_printf("%*c\n", 12, 'e');
	printf("%*c\n", 12, 'e');
	ft_printf("%c\n", '\0');
	printf("%c\n", '\0');
}
