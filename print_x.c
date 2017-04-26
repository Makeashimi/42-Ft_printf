/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:59:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/26 19:50:43 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		param_before(va_list *ap, t_param *param)
{
	if (param->l || param->ll)
	{
		param->arglong = va_arg(*ap, unsigned long);
		if (param->arglong == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->arglong, 16);
	}
	else if (param->j)
	{
		param->max = va_arg(*ap, uintmax_t);
		if (param->max == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->max, 16);
	}
	else if (param->z)
	{
		param->size = va_arg(*ap, ssize_t);
		if (param->size == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->size, 16);
	}
	else if (param->hh)
	{
	 	param->argchar = (unsigned char)va_arg(*ap, int);
	 	if (param->argchar == 0 && check_width(param) == 1)
			return (1);
	 	param->str = ft_uitoabase(((unsigned char)param->argchar), 16);
	}
	else if (param->h)
	{
		param->argshort = va_arg(*ap, int);
		if (param->argshort == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_uitoabase(param->argshort, 16);
	}
	else
	{
		param->argint = va_arg(*ap, unsigned int);
		if (param->argint == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_uitoabase(param->argint, 16);
	}
	param->sizestr = ft_strlen(param->str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	return (0);
}

void		print_x(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	if (param_before(ap, param) == 1)
		return ;
	//printf("%d\n", param->sharp);
	if (param->sharp && *(param->str) != '0')
	{
		ft_putstr("0x");
		param->number = param->number + 2;
	}
	param_precision(param);
	param_zero(param);
	print_arg(param, param->str, i);
	param_minus(param);
	ft_strdel(&param->str);
}

void		print_xup(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	if (param_before(ap, param) == 1)
		return ;
	if (param->sharp && *(param->str) != '0')
	{
		ft_putstr("0X");
		param->number = param->number + 2;
	}
	param_precision(param);
	param_zero(param);
	while (param->str[i] != '\0')
	{
		ft_putchar(ft_toupper(param->str[i]));
		param->number++;
		i++;
	}
	param_minus(param);
	ft_strdel(&param->str);
}
