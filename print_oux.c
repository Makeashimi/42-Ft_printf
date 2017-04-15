/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:20:57 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/10 16:56:03 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_oup(va_list *ap, t_param *param)
{
	char			*str;
	unsigned long	nb;
	int				i;
	int				size;

	i = 0;
	nb = va_arg(*ap, unsigned long);
	str = ft_ultoabase(nb, 8);
	size = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param, size);
	param_precision(param, size);
	if (param->sharp && nb > 0)
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

void	print_u(va_list *ap, t_param *param)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	str = ft_uitoabase(va_arg(*ap, unsigned int), 10);
	size = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param, size);
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

void	print_uup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_ultoabase(va_arg(*ap, unsigned long), 10);
	param_width(param, ft_strlen(str));
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, ft_strlen(str));
	ft_strdel(&str);
}

void	print_x(va_list *ap, t_param *param)
{
	char			*str;
	unsigned int	nb;
	int				i;
	int				size;

	i = 0;
	nb = va_arg(*ap, unsigned int);
	str = ft_uitoabase(nb, 16);
	size = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param, size);
	param_precision(param, size);
	if (param->sharp && nb > 0)
	{
		ft_putstr("0x");
		param->number = param->number + 2;
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

void	print_xup(va_list *ap, t_param *param)
{
	char			*str;
	unsigned int	nb;
	int				i;
	int				size;

	i = 0;
	nb = va_arg(*ap, unsigned int);
	str = ft_uitoabase(nb, 16);
	size = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param, size);
	param_precision(param, size);
	if (param->sharp && nb > 0)
	{
		ft_putstr("0X");
		param->number = param->number + 2;
	}
	param_zero(param, size);
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, size);
	ft_strdel(&str);
}
