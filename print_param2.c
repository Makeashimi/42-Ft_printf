/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:25:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/14 22:54:24 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	param_width(t_param *param, int len)
{
	int		widthcopy;

	widthcopy = param->width;
	if (param->space)
		widthcopy--;
	if (param->precision && param->width <= param->precision)
		return ;
	else if (param->precision)
		widthcopy = widthcopy - param->precision - len - lensharp(param);
	if (param->precision == 0)
		widthcopy = widthcopy - len - lensharp(param);
	//printf("%d\n", widthcopy);
	//widthcopy = 4;
	if (widthcopy && param->minus == 0 && param->zero == 0)
	{
		while (widthcopy > 0)
		{
			ft_putchar(' ');
			widthcopy--;
			param->number++;
		}
	}
}

void	param_widthstr(t_param *param, int len)
{
	int		widthcopy;

	widthcopy = param->width;
	//printf("%d\n", widthcopy);
	if (param->precision && len == 0)
		widthcopy = widthcopy - len;
	else if (param->precision && param->width >= param->precision && len <=
														param->precision)
		widthcopy = widthcopy - param->precision + len;
	else if (param->precision && param->width >= param->precision &&
												len >= param->precision)
		widthcopy = widthcopy - param->precision;
	else
		widthcopy = widthcopy - len;
	//printf("%d\n", widthcopy);
	while (widthcopy > 0 && param->zero == 0 && param->minus == 0)
	{
		ft_putchar(' ');
		widthcopy--;
		param->number++;
	}
}

void	param_widthwchart(t_param *param, wchar_t *str, int len)
{
	int		widthcopy;
	int		size;
	int		i;

	i = 0;
	size = whatsize(str[i]);
	if (param->precision)
	{
		while (size + whatsize(str[i + 1]) <= param->precision)
		{
			size = size + whatsize(str[i + 1]);
			i++;
		}
		widthcopy = param->width - size;
	}
	else
		widthcopy = param->width - len;
	while (widthcopy > 0 && param->zero == 0 && param->minus == 0)
	{
		ft_putchar(' ');
		widthcopy--;
		param->number++;
	}
}

void	param_zero(t_param *param, int len)
{
	int		widthcopy;

	widthcopy = param->width - len - lensharp(param);
	if (param->zero && param->minus == 0 && param->precision == 0)
	{
		while (widthcopy > 0)
		{
			ft_putchar('0');
			widthcopy--;
			param->number++;
		}
	}
}

void	print_pourcent(va_list *ap, t_param *param)
{
	(void)ap;
	param_width(param, 1);
	param_zero(param, 1);
	ft_putchar('%');
	param->number++;
	param_minus(param, 1);
}
