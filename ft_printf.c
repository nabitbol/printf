/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:20:07 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/26 12:29:17 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			ft_value_giver(&str, &count, ap);
		else
		{
			write(1, str, 1);
			count += 1;
		}
		str++;
	}
	va_end(ap);
	return (count);
}
