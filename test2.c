#include "ft_printf.h"


int	main(void)
{
	int x = 10;
	char *g= "15623";
	int u = 24113;
	char *tmp = "j";

	ft_printf("yooyooo %4d\n", x);
	printf("yooyooo %4d\n", x);
	ft_printf("yooyooo %05s\n", tmp);
	printf("yooyooo %05s\n", tmp);
	ft_printf("yooyooo %i\n", x);
	printf("yooyooo %i\n", x);
	ft_printf("yooyooo %2u\n", x);
	printf("yooyooo %u\n", x);
	ft_printf("yooyooo %x\n", u);
	printf("yooyooo %x\n", u);
	ft_printf("yooyooo %X\n", u);
	printf("yooyooo %X\n", u);
	ft_printf("yooyoyo %p\n", g);
	printf("yooyoyo %p\n", g);
}
