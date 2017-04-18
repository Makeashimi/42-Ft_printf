/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:12:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/05 17:23:15 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lensharp(t_param *param)
{
	const char	*str = "sSpdDioOuUxXcC/*eEfFgGaAn*/";

	if (param->sharp)
	{
		if (str[param->type] == 'x' || str[param->type] == 'X')
			return (2);
		else if (str[param->type] == 'o' || str[param->type] == 'O')
			return (1);
	}
	else if (str[param->type] == 'p')
		return (2);
	return (0);
}

void	param_minus(t_param *param, int size)
{
	//printf("\nwidth : %d\n", param->width);
	//printf("\nprecision : %d\n", size);
	if (param->plus)
		param->width--;
	if (param->precision && size == 0)
		param->width = param->width - size;
	else if (param->precision)
		param->width = param->width - param->precision - lensharp(param);
	else
		param->width = param->width - size - lensharp(param);
	//printf("\nsize : %d\n", size);
	//printf("\nwidth : %d\n", param->width);
	if (param->minus)
	{
		while (param->width > 0)
		{
			ft_putchar(' ');
			param->number++;
			param->width--;
		}
	}
}

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
	if (param->plus == 0 && param->space)
	{
		ft_putchar(' ');
		param->number++;
	}
}
