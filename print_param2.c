/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:25:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/07 17:30:54 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	param_width(t_param *param, int len)
{
	int		widthcopy;

	//printf("%d\n", param->width);
	//printf("%d\n", param->precision);
	widthcopy = param->width;
	if (param->precision && param->width <= param->precision)
		return ;
	else if (param->precision)
	{
		widthcopy = widthcopy - param->precision - len - lensharp(param);
		//printf("%d\n", widthcopy);
	}
	if (param->precision == 0)
		widthcopy = widthcopy - len - lensharp(param);
	//printf("%d\n", widthcopy);
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

void	param_precisioninteger(t_param *param)
{
	int		precisioncopy;
	
	precisioncopy = param->precision - lensharp(param);
	while (param->precision && precisioncopy > 0)
	{
		ft_putchar('0');
		precisioncopy--;
		param->number++;
	}
}


void	param_precisionstr(t_param *param, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && param->precision > i)
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
}

void	print_pourcent(va_list *ap, t_param *param)
{
	(void) ap;
	param_width(param, 1);
	param_zero(param, 1);
	ft_putchar('%');
	param->number++;
	param_minus(param, 1);
}
