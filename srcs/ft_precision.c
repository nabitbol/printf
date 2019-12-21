/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:21:40 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/21 18:28:05 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_isflag(char c)
{
	char	*flags;

	flags = "cspdiuxX%";
	while (*flags)
	{
		if (c == *flags)
			return(0);
		flags++;
	}
	return (1);
}

void	ft_check_prec(const char **str, t_convert *ptr, va_list ap, int *count)
{
	while (ft_isflag(**str) == 1)
	{
		if (*str[0] == '0')
			ptr->zero = 1;
		else if (is_digit(**str) == 1)
			ptr->num = (ptr->num * 10) + (**str - '0');
		else if (**str == '-')
			ptr->moins = 1;
		else if (**str == '.')
			ptr->point = 1;
		else if (**str == '*')
			ptr->etoile = va_arg(ap, int);
		if (**str == '*' && ptr->point == 1)
			ptr->p = va_arg(ap, int);
		else if (is_digit(**str) == 1 && ptr->point1 == 1)
			ptr->p = (ptr->p * 10) + (**str - '0');
		else if (is_digit(**str) == 1 && ptr->point == 1)
			ptr->p = (ptr->p * 10) + (**str - '0');
		if (**str != '.' && **str != '*' && **str != '-' && **str != '0' &&
				is_digit(**str) == 0)
			ft_putchar_count(**str, count);
		(*str)++;
	}
}

void		print_prec(t_convert *ptr, const char **str, int *count)
{
	if ((ptr->moins == 0 && ptr->zero == 0) || (ptr->zero == 1 && **str == 's') ||
	(ptr->point == 1 && (ptr->p > ptr->num)))
		print_espace(ptr, str, count);
	else if (ptr->zero == 1 && ptr->moins == 0 && **str != 'c'  && **str != 's'&&
	ptr->point == 0)
		print_zero(ptr, str, count);
	else if (ptr->moins == 0 && ptr->point == 1 && **str!= 's')
		printf_eszero(ptr, str, count);
}

void		print_espace(t_convert *ptr, const char **str, int *count)
{
	int				len;
	int				n;

	n = 0;
	len = 0;
	if (**str == 'd' || **str == 'i')
		len = counter(ptr->integer, 10);
	else if (**str == 's')
		len = ft_strlen(ptr->string);
	else if (**str == 'x' || **str == 'X')
		len = counter(ptr->u_integer, 16);
	else if (**str == 'u')
		len = counter(ptr->u_integer, 10);
	while ((ptr->num - len) > n)
	{
		ft_putchar_count(' ', count);
		n++;
	}
}


void	print_zero(t_convert *ptr, const char **str, int *count)
{
	int				len;
	int				n;

	n = 0;
	len = 0;
	if (**str == 'd' || **str == 'i')
		len = counter(ptr->integer, 10);
	else if (**str == 's')
		len = ft_strlen(ptr->string);
	else if (**str == 'x' || **str == 'X')
		len = counter(ptr->u_integer, 16);
	else if (**str == 'u')
		len = counter(ptr->u_integer, 10);
	else if (**str == 'p')
		len = counter(ptr->u_integer, 16) + 2;
	while (ptr->num - len > n)
	{
		ft_putchar_count('0', count);
		n++;
	}
}
