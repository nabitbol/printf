/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:18:11 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/21 18:27:12 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printf_eszero(t_convert *ptr, const char **str, int *count)
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
	while ((ptr->num > ptr->p) && (ptr->num - len) > n)
	{
		ft_putchar_count(' ', count);
		n++;
	}
	n = 0;
	while ((ptr->p - len) > n)
	{
		ft_putchar_count('0', count);
		n++;
	}
}
