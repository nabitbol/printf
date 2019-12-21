/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:21:40 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/14 13:19:33 by nabitbol         ###   ########.fr       */
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

void	ft_check_precision(const char **str, t_convert *ptr, va_list ap, int *count)
{

	while (ft_isflag(**str) == 1)
	{
		if (is_digit(**str) == 1)
			ptr->num = (ptr->num * 10) + (**str - '0');
		else if (**str == '-')
			ptr->moins = 1;
		else if (**str == '0')
			ptr->zero = 1;
		else if (**str == '.')
			ptr->point = 1;
		else if (**str == '*')
			ptr->etoile = va_arg(ap, int);
		if (**str == '*' && ptr->point == 1)
			ptr->p = va_arg(ap, int);
		else if (is_digit(**str) == 1 && ptr->point == 1)
			ptr->p = (ptr->num * 10) + (**str - '0');
		if (**str != '.' && **str != '*' && **str != '-' && **str != '0' && is_digit(**str) == 0)
			ft_putchar_count(**str, count);
		(*str)++;
	}
}

void	print_precision(t_convert *ptr, int *count, const char **str)
{
	int	len;
	int	d;
	char	*s;

	if (**str == 'd' || **str == 'u' || **str == 'i' || **str == 'x' || **str == 'X')
	{
		d = ptr->integer;
		len = ft_strlen_int(d);
		while (ptr->num > len)
		{
			ft_putchar_count(' ',count);
			ptr->num--;
		}
	}
	else if (**str == 's')
	{
		s = ptr->string;
		len = ft_strlen(s);
		while (ptr->num > len)
		{
			ft_putchar_count(' ', count);
			ptr->num--;
		}
	}
}


void	ft_zero_point(t_convert *ptr, int *count, int len, const char **str)
{
	if (ptr->zero == 1 && ptr->num != 0)
	{
		while (ptr->num > len)
		{
			ft_putchar_count('0',  count);
			ptr->num--;
		}
	}
	else if (ptr->num != 0 && ptr->point == 1 && ptr->p == 0 && **str != 's')
	{
		while (ptr->num > len)
		{
			ft_putchar_count(' ', count);
			ptr->num--;
		}
	}
	else if (ptr->num != 0 && ptr->point == 1 && ptr->p != 0 && **str != 's')
	{
		while ((ptr->num > len) && (ptr->num > ptr->p))
		{
			ft_putchar_count(' ', count);
			ptr->num--;
		}
		while (ptr->p > len)
		{
			ft_putchar_count(' ', count);
			ptr->p--;
		}
	}
}


