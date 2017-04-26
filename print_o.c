/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:46:20 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/26 19:52:15 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		param_before(va_list *ap, t_param *param)
{
	if (param->l || param->ll)
	{
		param->arglong = va_arg(*ap, unsigned long);
		if (param->arglong == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->arglong, 8);
	}
	else if (param->j)
	{
		param->max = va_arg(*ap, uintmax_t);
		if (param->max == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->max, 8);
	}
	else if (param->z)
	{
		param->size = va_arg(*ap, ssize_t);
		if (param->size == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->size, 8);
	}
	else if (param->hh)
	{
		param->argchar = (unsigned char)va_arg(*ap, int);
		if (param->argchar == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
	 	param->str = ft_uitoabase(((unsigned char)param->argchar), 8);
	}
	else if (param->h)
	{
		param->argshort = va_arg(*ap, int);
		if (param->argshort == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_uitoabase(param->argshort, 8);
	}
	else
	{
		param->argint = va_arg(*ap, unsigned int);
		if (param->argint == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_uitoabase(param->argint, 8);
	}
	param->sizestr = ft_strlen(param->str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	return (0);
}

void		print_o(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	if (param_before(ap, param) == 1)
		return ;
	if (param->sharp && *(param->str) != '0')
	{
		ft_putchar('0');
		param->number++;
		if (param->precision)
			param->precision--;
	}
	param_precision(param);
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
	if (param->arglong == 0 && param->sharp == 0 && check_width(param) == 1)
		return ;
	str = ft_ultoabase(param->arglong, 8);
	param->sizestr = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	if (param->sharp && *(str) != '0')
	{
		ft_putchar('0');
		param->number++;
		if (param->precision)
			param->precision--;
	}	
	param_precision(param);
	param_zero(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}
