/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:15:25 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/26 12:19:38 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

/* structure */
typedef struct	s_convert
{
	char	flag;
	char	*string;
	char	chara;
	int		integer;
	unsigned int	u_integer;
	int		point;
	int		zero;
	int		point1;
	int		moins;
	int		p;
	int		num;
}			t_convert;

#precision
int			ft_isflag(char c);
void		ft_prec(const char **str, t_convert *ptr, va_list ap, int *count);
void		print_prec(t_convert *ptr, const char **str, int *count);
void		print_espace(t_convert *ptr, const char **str, int *count);
void		print_zero(t_convert *ptr, const char **str, int *count);
int			print_espace2(t_convert *ptr, const char **str, int len);

#precision2
int			print_negatifz(t_convert *ptr, int *count, int nb_zero);
void		prec_s(t_convert *ptr, int *count);
int			check_point(t_convert *ptr, const char **str);
void		if_point_neg(t_convert *ptr);

#utils1
void		ft_putchar_count(unsigned char c, int *count);
void		ft_putstr_count(char *str, int *count);

#utils2
void		ft_putchar(char c);
void		ft_putnbr_count(long nbr, int *count);
void		ft_putnbr_hexa(long nbr, int *count);
void		ft_putnbr_hexa_small(long nbr, int *count);
void		ft_putadrr(t_convert *ptr, va_list ap);

#utils3
int			is_digit(char c);
size_t		ft_strlen(const char *s);
size_t		counter(long int d, int div);

#parser
t_convert	*init_convert(void);
void		ft_check_flags(t_convert *ptr, int *count);
void		ft_value_giver(const char **str, int *count, va_list ap);
void		negatif(t_convert *ptr, const char **str, int *count);
#printf
int			ft_printf(const char *, ...);

#endif
