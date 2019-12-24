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

int	print_negatifz(t_convert *ptr, int *count, int nb_zero)
{
	ft_putchar_count('-', count);
	ptr->integer = -(ptr->integer);
	if (ptr->point == 0)
		nb_zero -= 1;
	if (ptr->moins == 1)
		ptr->num -=1;
	return (nb_zero);
}

void	prec_s(t_convert *ptr, int *count)
{
	int	n;
	char	*s;

	n = 0;
	s = ptr->string;
	while (s[n] &&  n < ptr->p)
	{
		ft_putchar_count(s[n], count);
		n++;
	}
}


int		check_point(t_convert *ptr, const char **str)
{
	if ((**str == 'd' || **str == 'i') && ptr->p == 0 &&
		ptr->integer == 0 && ptr->point == 1)
		return (1);
	if ((**str == 'd' || **str == 'i') && ptr->point == 0 &&
		ptr->integer == 0  && ptr->point == 1)
		return (1);
	else if (ptr->p == 0 && ptr->u_integer == 0 && ptr->point == 1 &&
		(**str == 'x' || **str == 'X' || **str == 'u'))
		return (1);
	else if (ptr->point1 == 0 && ptr->u_integer == 0 && ptr->point == 1 &&
		(**str == 'x' || **str == 'X' || **str == 'u'))
		return (1);
	else 
		return (0);
}
