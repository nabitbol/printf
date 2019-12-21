/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:10:32 by nabitbol          #+#    #+#             */
/*   Updated: 2019/12/14 13:55:13 by nabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_convert	*init_convert(void)
{
	t_convert *conv_list;

	conv_list = NULL;
	if (!(conv_list = (t_convert *)malloc(sizeof(t_convert))))
		return (NULL);
	conv_list->integer = 0;
	conv_list->u_integer = 0;
	conv_list->point = 0;
	conv_list->zero = 0;
	conv_list->etoile = 0;
	conv_list->moins = 0;
	conv_list->p = 0;
	conv_list->num = 0;
	return (conv_list);
}

void		ft_check_flags(t_convert *ptr, int *count)	
{
	if (ptr->flag == 'c')
		ft_putchar_count(ptr->chara, count);
	else if (ptr->flag == 'd' || ptr->flag == 'i')
		ft_putnbr_count(ptr->integer, count);
	else if (ptr->flag == 'p')
		ft_putadrr(ptr->string, count);
	else if (ptr->flag == 'u')
		ft_putnbr_count(ptr->u_integer, count);
	else if (ptr->flag == 'x')
		ft_putnbr_hexa_small(ptr->u_integer, count);
	else if (ptr->flag == 'X')
		ft_putnbr_hexa(ptr->u_integer, count);
	else if (ptr->flag == 's')
		ft_putstr_count(ptr->string, count);
	else if (ptr->flag == '%')
		ft_putchar_count('%', count);
	free(ptr);
}


void		ft_value_giver(const char **str, int *count, va_list ap)
{
	t_convert *ptr;

	ptr = init_convert();
	(*str)++;
	ft_check_precision(str, ptr, ap, count);
	ptr->flag = **str;
	if (ptr->flag == 's')
		ptr->string = va_arg(ap, char *);
	else if (ptr->flag == 'p')
		ptr->string = va_arg(ap, char *);
	else if (ptr->flag == 'u' || ptr->flag == 'x' || ptr->flag == 'X')
		ptr->u_integer = va_arg(ap, int);
	else if (ptr->flag != '%')
		ptr->integer = va_arg(ap, int);
	else if (ptr->flag == 's' && ptr->string == NULL)
		ptr->string = "(null)";
	print_precision(ptr, count, str);
	ft_check_flags(ptr, count);	
}
