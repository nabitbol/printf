/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:22:15 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/21 18:17:29 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t		n;

	n = 0;
	if (s == 0)
		return (0);
	while (s[n])
		n++;
	return (n);
}

size_t		counter(long int d, int div)
{
	int n;

	n = 0;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		d = (d / div);
		n++;
	}
	return (n);
}
