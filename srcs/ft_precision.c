/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:31:24 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/26 16:33:56 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_isflag(char c)
{
	char	*flags;

	flags = "cspdiuxX%";
	while (*flags)
	{
		if (c == *flags)
			return (0);
		flags++;
	}
	return (1);
}

void		p(const char **str, t_convert *ptr, va_list ap, int *count)
{
	if (**str == '0')
		ptr->zero = 1;
	while (ft_isflag(**str) == 1)
	{
		if (**str == '-')
			ptr->moins = 1;
		else if (**str == '.')
			ptr->point = 1;
		if ((is_digit(**str) == 1 || **str == '*') && ptr->point == 1)
			ptr->point1 = 1;
		if (**str == '*' && ptr->point == 0)
			ptr->num = va_arg(ap, int);
		else if (**str == '*' && ptr->point == 1)
			ptr->p = va_arg(ap, int);
		if (is_digit(**str) == 1 && ptr->point == 0)
			ptr->num = (ptr->num * 10) + (**str - '0');
		else if (is_digit(**str) == 1 && ptr->point == 1)
			ptr->p = (ptr->p * 10) + (**str - '0');
		if (**str != '.' && **str != '*' && **str != '-' && **str != '0' &&
				is_digit(**str) == 0)
			ft_putchar_count(**str, count);
		(*str)++;
	}
	if_point_neg(ptr);
}

void		print_prec(t_convert *ptr, const char **str, int *count)
{
	if ((ptr->moins == 0 && ptr->zero == 0) ||
		(ptr->zero == 1 && **str == 's') ||
		(ptr->point == 1 && ptr->zero == 1 && ptr->moins == 0))
		print_espace(ptr, str, count);
	else if (ptr->zero == 1 && ptr->moins == 0 && **str != 's' &&
		**str != 'c' && ptr->point == 0)
		print_zero(ptr, str, count);
	if (**str == 's' && ptr->point == 1)
		prec_s(ptr, count);
	else if (ptr->point == 1 && **str != '%' && **str != 'c')
		print_zero(ptr, str, count);
	if (**str == 'p')
		ft_putstr_count("0x", count);
}

void		print_espace(t_convert *ptr, const char **str, int *count)
{
	int		len;
	int		n;

	n = 0;
	len = 0;
	if (**str == 'c' && (ptr->integer < 0 || ptr->integer > 132))
		len = 0;
	else if (**str == 'c')
		len = 1;
	else if (**str == 'd' || **str == 'i')
		len = counter(ptr->integer, 10);
	else if (**str == 's')
		len = ft_strlen(ptr->string);
	else if (**str == 'p')
		len = counter(ptr->ulong_integer, 16) + 2;
	else if (**str == 'x' || **str == 'X')
		len = counter(ptr->u_integer, 16);
	else if (**str == 'u')
		len = counter(ptr->u_integer, 10);
	len = print_espace2(ptr, str, len);
	while ((ptr->num - len) > n)
	{
		ft_putchar_count(' ', count);
		n++;
	}
}

void		print_zero(t_convert *ptr, const char **str, int *count)
{
	int		len;
	int		n;
	int		nb_zero;

	n = 0;
	len = 0;
	nb_zero = (ptr->point == 1) ? ptr->p : ptr->num;
	if (**str == 'c' || **str == '%')
		len += 1;
	else if (**str == 'd' || **str == 'i')
		len = counter(ptr->integer, 10);
	else if (**str == 'x' || **str == 'X')
		len = counter(ptr->u_integer, 16);
	else if (**str == 'u')
		len = counter(ptr->u_integer, 10);
	else if (**str == 'p')
		len = counter(ptr->ulong_integer, 16) + 2;
	if (ptr->integer < 0)
		nb_zero = print_negatifz(ptr, count, nb_zero);
	while (nb_zero - len > n)
	{
		ft_putchar_count('0', count);
		n++;
	}
}
