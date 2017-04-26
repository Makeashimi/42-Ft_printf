/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:19:58 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/26 18:37:52 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void		param_before(va_list *ap, t_param *param)
// {
	
// }

static void		print_dwithl(t_param *param, char *str)
{
	int		i;

	i = 0;
	if (param->precision > 0 && str[i] == '-')
		param->precision++;
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	if (param->plus && param->minus == 0 && param->zero == 0)
		param->sizestr++;
	param_space(param);
	param_width(param);
	param_plus(param, param->arglong);
	if (str[i] == '-')
	{
		ft_putchar('-');
		param->number++;
		i++;
	}
	if (param->zero && param->space)
		param->sizestr++;
	param_precision(param);
	param_zero(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}

static void		print_simpled(t_param *param, char *str, int argint)
{
	int		i;

	i = 0;
	if (param->precision > 0 && str[i] == '-')
		param->precision++;
	if (param->minus == 0)
		param->precision = param->precision - param->sizestr;
	if (param->precision < 0)
		param->precision = 0;
	if (param->plus && param->minus == 0 && (argint >= 0 || param->zero == 0))
		param->sizestr++;
	if (argint >= 0)
		param_space(param);
	param_width(param);
	param_plus(param, argint);
	if (str[i] == '-')
	{
		ft_putchar('-');
		param->number++;
		i++;
	}
	if (param->zero && param->space)
		param->sizestr++;
	param_precision(param);
	param_zero(param);
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}

void			print_d(va_list *ap, t_param *param)
{
	char			*str;
	int				argint;
	char			c;
	short			argshort;
	int				i;
	long			l;

	i = 0;
	if (param->l || param->ll)
	{
		l = va_arg(*ap, long);
		if (l == 0 && check_width(param) == 1)
			return ;
		str = ft_ltoabase(l, 10);
		param->sizestr = ft_strlen(str);
		print_dwithl(param, str);
	}
	else if (param->j)
	{
		param->max = va_arg(*ap, uintmax_t);
		if (param->max == 0 && check_width(param) == 1)
			return ;
		str = ft_ltoabase(param->max, 10);
		param->sizestr = ft_strlen(str);
		print_dwithl(param, str);
	}
	else if (param->z)
	{
		param->size = va_arg(*ap, ssize_t);
		if (param->size == 0 && check_width(param) == 1)
			return ;
		str = ft_ltoabase(param->size, 10);
		param->sizestr = ft_strlen(str);
		print_dwithl(param, str);
	}
	else if (param->hh)
	{
		c = va_arg(*ap, int);
		if (c == 0 && check_width(param) == 1)
			return ;
	 	str = ft_itoa((char)c);
		param->sizestr = ft_strlen(str);
	 	print_dwithl(param, str);
	}
	else if (param->h)
	{
		argshort = va_arg(*ap, int);
		if (argshort == 0 && check_width(param) == 1)
			return ;
		str = ft_itoabase(argshort, 10);
		param->sizestr = ft_strlen(str);
	 	print_dwithl(param, str);
	}
	else
	{
		argint = va_arg(*ap, int);
		if (argint == 0 && check_width(param) == 1)
			return ;
		str = ft_itoa(argint);
		param->sizestr = ft_strlen(str);
		print_simpled(param, str, argint);
	}
}

void			print_dup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;
	long	n;

	i = 0;
	n = va_arg(*ap, long);
	str = ft_ltoabase(n, 10);
	param->sizestr = ft_intlen(n);
	param_plus(param, n);
	if (n >= 0)
		param_space(param);
	param_width(param);
	param_zero(param);
	if (param->plus && n >= 0)
	{
		ft_putchar('+');
		param->number++;
	}
	print_arg(param, str, i);
	param_minus(param);
	ft_strdel(&str);
}

void			print_i(va_list *ap, t_param *param)
{
	print_d(ap, param);
}
