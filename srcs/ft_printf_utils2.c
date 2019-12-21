/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:22:06 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/14 09:22:09 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr_count(long nbr, int *count)
{
	unsigned long  nb;

	nb = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = nbr * -1;
		*count += 1;
	}
	if (nbr >= 10)
		ft_putnbr_count((nb / 10), count);
	*count += 1;
	ft_putchar((nb % 10) + '0');
}

void	ft_putnbr_hexa(long nbr, int *count)
{
	char		*str;
	unsigned long	nb;

	str = "0123456789ABCDEF";
	nb = nbr;
	if (nb >= 16)
		ft_putnbr_hexa((nb / 16), count);
	ft_putchar(str[nb%16]);
	*count += 1;
}

void	ft_putnbr_hexa_small(long nbr, int *count)
{
	char 		*str;
	unsigned long	nb;

	str = "0123456789abcdef";
	nb = nbr;
	if (nb >= 16)
		ft_putnbr_hexa_small((nb / 16), count);
	ft_putchar(str[nb%16]);
	*count += 1;
}

void	ft_putadrr(char *str, int *count)
{
	unsigned long int d;

	d = (unsigned long int)str;
	ft_putstr_count("0x", count);
	ft_putnbr_hexa_small(d, count);
}
