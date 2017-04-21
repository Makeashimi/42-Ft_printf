/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:20:57 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/21 16:08:12 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_p(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_ultoabase(va_arg(*ap, unsigned long), 16);
	param->sizestr = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	ft_putstr("0x");
	param->number = param->number + 2;
	param_zero(param);
	param_precision(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}

void	print_u(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	if (param->l || param->ll)
		str = ft_ultoabase(va_arg(*ap, unsigned long), 10);
	else if (param->j)
		str = ft_ultoabase(va_arg(*ap, uintmax_t), 10);
	else if (param->z)
		str = ft_ultoabase(va_arg(*ap, ssize_t), 10);
	else if (param->hh)
	 	str = ft_uitoabase((unsigned char)va_arg(*ap, int), 10);
	else if (param->h)
		str = ft_uitoabase(va_arg(*ap, int), 10);
	else
		str = ft_uitoabase(va_arg(*ap, unsigned int), 10);
	param->sizestr = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param);
	param_precision(param);
	param_zero(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}

void	print_uup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_ultoabase(va_arg(*ap, unsigned long), 10);
	param->sizestr = ft_strlen(str);
	param_width(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}
