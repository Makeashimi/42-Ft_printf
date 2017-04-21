/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:46:20 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/21 16:07:14 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		param_before(va_list *ap, t_param *param)
{
	if (param->l || param->ll)
	{
		param->arglong = va_arg(*ap, unsigned long);
		param->str = ft_ultoabase(param->arglong, 8);
	}
	else if (param->j)
	{
		param->max = va_arg(*ap, uintmax_t);
		param->str = ft_ultoabase(param->max, 8);
	}
	else if (param->z)
	{
		param->size = va_arg(*ap, ssize_t);
		param->str = ft_ultoabase(param->size, 8);
	}
	else if (param->hh)
	{
		param->argchar = (unsigned char)va_arg(*ap, int);
	 	param->str = ft_uitoabase(((unsigned char)param->argchar), 8);
	}
	else if (param->h)
	{
		param->argshort = va_arg(*ap, int);
		param->str = ft_uitoabase(param->argshort, 8);
	}
	else
	{
		param->argint = va_arg(*ap, unsigned int);
		param->str = ft_uitoabase(param->argint, 8);
	}
	param->sizestr = ft_strlen(param->str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	param_precision(param);
}

void		print_o(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	param_before(ap, param);
	if (param->sharp && param->argint > 0)
	{
		ft_putchar('0');
		param->number++;
	}
	param_zero(param);
	print_arg(param, param->str, i);
	param_minus(param);
	ft_strdel(&param->str);
}

void		print_oup(va_list *ap, t_param *param)
{
	char			*str;
	int				i;

	i = 0;
	param->arglong = va_arg(*ap, unsigned long);
	str = ft_ultoabase(param->arglong, 8);
	param->sizestr = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	param_precision(param);
	if (param->sharp && param->arglong > 0)
	{
		ft_putchar('0');
		param->number++;
	}
	param_zero(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}
