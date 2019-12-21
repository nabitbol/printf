#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


//j' ai retirer les static car on ne peux pas utiliser le variables priver dans le .h
int			ft_check_0(char* ptr);
void		ft_free(char *ptr,int f);
int			ft_printf(const char *, ...);
int			ft_count_mem(int w);
int			ft_check_point(char* ptr);
int			ft_check_point2(char* ptr);
int			ft_rev_num(int w);
int			 ft_check_leng(int w, int t);
char*		ft_change2(char* ptr);
char*		 ft_change(char* ptr, int w, int z);
char		*ft_change3(char* ptr, int i);
int			lon(long nb);
size_t		ft_strlen(const char *s);
int			ft_putadrr(unsigned long int d);
int			ft_check_star(char* ptr);
int			ft_check_2(const char* s, int i, va_list ap, char *ptr);
int			ft_checker(const char* s, int i);
char*		convert_hexa_small(long unsigned int d);
char*		rev_hex(char* itoa);
char*		ft_itoa(int n);
int			size_hex(int d);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_neg_check(int y, char* ptr, char* s);
char		*ft_strjoin(char const *s1, char const *s2);
long unsigned int	ft_atoi(const char* str);
char*		u_itoa(unsigned int n);
int			size_itoa(int n);
char		*rev_itoa(char *itoa);
char	*ft_check_precision(char *ptr, va_list ap, int *f, int *k);
int			ft_precision_d1(int y, char* ptr, char *s, int k);
int 		ft_precision_d2(int y, char* ptr, char* s, int k);
int 		ft_precision_c1(int y, char* ptr);
int 		ft_precision_c2(int y, char* ptr);
int 		ft_precision_s1(int y, char* ptr, char* s);
int 		ft_precision_s2(int y, char* ptr, char* s);
int			ft_precision_p1(int y, char* ptr, int p);
int			ft_precision_p2(int y, char* ptr, int p, int k);
char*		convert_hexa(unsigned long int d);
int 		ft_check_star(char* ptr);
int		ft_putadrr_count(unsigned long int d);
int		flag_c(va_list ap, char *ptr);
int		flag_s(va_list ap, char *ptr);
int		flag_p(va_list ap, char *ptr);
int		flag_d(va_list ap, char *ptr);
int		flag_i(va_list ap, char *ptr);
int		flag_u(va_list ap, char *ptr);
int		flag_x(va_list ap, char *ptr);
int		flag_X(va_list ap, char *ptr);
int		flag_M(va_list ap);


#endif

