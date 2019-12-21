#include "ft_printf.h"


int	main(void)
{
	int x = 10;
	int g = 15623;
	char *tmp = "j";

	ft_printf("yooyooo %04d\n", x);
	printf("yooyooo %04d\n", x);
	ft_printf("yooyooo %5s\n", tmp);
	printf("yooyooo %5s\n", tmp);
	ft_printf("yooyooo %i\n", x);
	printf("yooyooo %i\n", x);
	ft_printf("yooyooo %u\n", x);
	printf("yooyooo %u\n", x);
	ft_printf("yooyooo %x\n", g);
	printf("yooyooo %x\n", g);
	ft_printf("yooyooo %X\n", g);
	printf("yooyooo %X\n", g);
	ft_printf("yooyoyo %p\n", g);
	printf("yooyoyo %p\n", g);
}
