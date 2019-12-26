#include "ft_printf.h"
#include <limits.h>
int				ft_printf(const char *str, ...);
int		main()
{
	ft_printf("%d\n", INT_MIN);
	printf("%d\n", INT_MIN);
	ft_printf ("'%c'\n", '\0');
	printf ("'%c'\n", '\0');
	//ft_printf("%10.s", NULL);
	printf("%10.s", NULL);
	ft_printf("%s", NULL);
	printf("%s", NULL);
}
