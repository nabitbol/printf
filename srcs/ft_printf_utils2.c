/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 09:22:06 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/26 16:31:55 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr_count(long int nbr, int *count)
{
	unsigned long int		nb;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			nb = nbr;
			ft_putstr_count("-2147483648", count);
		}
		else
		{
			ft_putchar('-');
			nb = -(nbr);
			*count += 1;
		}
	}
	else
		nb = nbr;
	if (nb >= 10 && nbr != -2147483648)
		ft_putnbr_count((nb / 10), count);
	if (nbr != -2147483648)
	{
		*count += 1;
		ft_putchar((nb % 10) + '0');
	}
}

void		ft_putnbr_hexa(long int nbr, int *count)
{
	char					*str;
	unsigned long			nb;

	str = "0123456789ABCDEF";
	nb = nbr;
	if (nb >= 16)
		ft_putnbr_hexa((nb / 16), count);
	ft_putchar(str[nb % 16]);
	*count += 1;
}

void		ft_putnbr_hexa_small(long int nbr, int *count)
{
	char						*str;
	unsigned long				nb;

	str = "0123456789abcdef";
	nb = nbr;
	if (nb >= 16)
		ft_putnbr_hexa_small((nb / 16), count);
	ft_putchar(str[nb % 16]);
	*count += 1;
}

void		ft_putadrr(t_convert *ptr, va_list ap)
{
	unsigned long int				d;

	ptr->string = va_arg(ap, char *);
	d = (unsigned long int)(ptr->string);
	ptr->ulong_integer = d;
}
