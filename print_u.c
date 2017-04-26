/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:20:57 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/26 19:07:39 by jcharloi         ###   ########.fr       */
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
		param->str = ft_ultoabase(param->arglong, 10);
	}
	else if (param->j)
	{
		param->max = va_arg(*ap, uintmax_t);
		if (param->max == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->max, 10);
	}
	else if (param->z)
	{
		param->size = va_arg(*ap, ssize_t);
		if (param->size == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_ultoabase(param->size, 10);
	}
	else if (param->hh)
	{
	 	param->argchar = (unsigned char)va_arg(*ap, int);
	 	if (param->argchar == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
	 	param->str = ft_uitoabase(((unsigned char)param->argchar), 10);
	}
	else if (param->h)
	{
		param->argshort = va_arg(*ap, int);
		if (param->argshort == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_uitoabase(param->argshort, 10);
	}
	else
	{
		param->argint = va_arg(*ap, unsigned int);
		if (param->argint == 0 && param->sharp == 0 && check_width(param) == 1)
			return (1);
		param->str = ft_uitoabase(param->argint, 10);
	}
	param->sizestr = ft_strlen(param->str);
	return (0);
}

void	print_u(va_list *ap, t_param *param)
{
	int		i;

	i = 0;
	if (param_before(ap, param) == 1)
		return ;
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	param_precision(param);
	param_zero(param);
	print_arg(param, param->str, i);
	param_minus(param);
	ft_strdel(&param->str);
}

void	print_uup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	param->arglong = va_arg(*ap, unsigned long);
	if (param->arglong == 0 && param->sharp == 0 && check_width(param) == 1)
		return ;
	str = ft_ultoabase(param->arglong, 10);
	param->sizestr = ft_strlen(str);
	param_width(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}
