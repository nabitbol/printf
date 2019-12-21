/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:21:58 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/21 18:17:37 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr_count(char *str, int *count)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
		*count += 1;
	}
}
