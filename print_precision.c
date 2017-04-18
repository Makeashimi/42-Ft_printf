/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:41:36 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/14 17:53:13 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	param_precision(t_param *param, int size)
{
	int		precisioncopy;

	precisioncopy = param->precision;
	//printf("%d\n", precisioncopy);
	//printf("%d\n", size);
	//printf("\n%d\n", precisioncopy);
	if (param->plus && param->minus)
		precisioncopy = param->precision - size;
	else if (param->minus && param->width <= param->precision && param->precision >= size)
		precisioncopy = param->precision - size;
	else if (param->minus)
		precisioncopy = param->width - param->precision - size;
	else
	{
		//printf("\n%d\n", precisioncopy);
		precisioncopy = param->precision;
		//printf("\n%d\n", precisioncopy);
	}
	//printf("\n%d\n", precisioncopy);
	while (param->precision && precisioncopy > 0)
	{
		ft_putchar('0');
		precisioncopy--;
		param->number++;
	}
	//printf("||\n");
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

void	param_precisionwchart(t_param *param, wchar_t *str, int size)
{
	int		i;
	int		stock;

	i = 0;
	stock = param->number;
	size = whatsize(str[i]);
	while (size <= param->precision)
	{
		print_wchart(str[i]);
		stock = param->number + size;
		size = size + whatsize(str[i + 1]);
		i++;
	}
	param->number = stock;
}
