/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:12:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/20 12:48:10 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	param_plus(t_param *param, int n)
{
	if (param->plus && n >= 0)
	{
		ft_putchar('+');
		param->number++;
	}
}

void	param_space(t_param *param)
{
	if (param->space && param->plus == 0 && param->precision == 0)
	{
		ft_putchar(' ');
		param->number++;
	}
}

void	param_zero(t_param *param)
{
	int		widthcopy;

	widthcopy = param->width - param->sizestr - lensharp(param);
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

void	param_minus(t_param *param)
{
	if (param->minus)
	{
		if (param->precision && param->plus)
			param->width = param->width - param->precision - 1;
		else if (param->precision && param->sizestr == 0)
			param->width = param->width - param->sizestr;
		else if (param->precision)
			param->width = param->width - param->precision - lensharp(param);
		else
			param->width = param->width - param->sizestr - lensharp(param);
		while (param->width > 0)
		{
			ft_putchar(' ');
			param->number++;
			param->width--;
		}
	}
}
