/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:19:58 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/14 21:32:40 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_dwithl(t_param *param, int size, char *str, unsigned long arglong)
{
	int		i;

	i = 0;
	if (param->precision > 0 && str[i] == '-')
		param->precision++;
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	if (param->plus && param->minus == 0 && param->zero == 0)
		size++;
	param_space(param);
	param_width(param, size);
	param_plus(param, arglong);
	if (str[i] == '-')
	{
		ft_putchar('-');
		param->number++;
		i++;
	}
	if ((param->zero && param->space))
		size++;
	param_precision(param, size);
	param_zero(param, size);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, size);
	ft_strdel(&str);
}

static void		print_simpled(t_param *param, int size, char *str, int argint)
{
	int		i;

	i = 0;
	if (param->precision > 0 && str[i] == '-')
		param->precision++;
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	if (param->plus && param->minus == 0 && (argint >= 0 || param->zero == 0))
		size++;
	if (argint >= 0)
		param_space(param);
	param_width(param, size);
	param_plus(param, argint);
	if (str[i] == '-')
	{
		ft_putchar('-');
		param->number++;
		i++;
	}
	if ((param->zero && param->space))
		size++;
	param_precision(param, size);
	param_zero(param, size);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, size);
	ft_strdel(&str);
}

void			print_d(va_list *ap, t_param *param)
{
	char			*str;
	unsigned long	arglong;
	int				argint;
	int				size;
	int				i;

	i = 0;
	if (param->l)
	{
		arglong = va_arg(*ap, unsigned long);
		str = ft_ltoabase(arglong, 10);
		size = ft_strlen(str);
		print_dwithl(param, size, str, arglong);
	}
	else
	{
		argint = va_arg(*ap, int);
		str = ft_itoa(argint);
		size = ft_strlen(str);
		print_simpled(param, size, str, argint);
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
	param_plus(param, n);
	if (n >= 0)
		param_space(param);
	param_width(param, ft_llen(n));
	param_zero(param, ft_llen(n));
	if (param->plus && n >= 0)
	{
		ft_putchar('+');
		param->number++;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, ft_llen(n));
	ft_strdel(&str);
}

void			print_i(va_list *ap, t_param *param)
{
	print_d(ap, param);
}

void			print_o(va_list *ap, t_param *param)
{
	char			*str;
	unsigned int	argint;
	unsigned long	arglong;
	int				i;
	int				size;

	i = 0;
	if (param->l)
	{
		arglong = va_arg(*ap, unsigned long);
		str = ft_ultoabase(arglong, 8);
	}
	else
	{
		argint = va_arg(*ap, unsigned int);
		str = ft_uitoabase(argint, 8);
	}
	size = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param, size);
	param_precision(param, size);
	if (param->sharp && argint > 0)
	{
		ft_putchar('0');
		param->number++;
	}
	param_zero(param, size);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, size);
	ft_strdel(&str);
}
