/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:36:05 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/26 19:36:36 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lensharp(t_param *param)
{
	const char	*str = "sSpdDioOuUxXcC";

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

void	print_pourcent(va_list *ap, t_param *param)
{
	(void)ap;
	param->sizestr = 1;
	param_width(param);
	param_zero(param);
	ft_putchar('%');
	param->number++;
	param_minus(param);
}

void	print_arg(t_param *param, const char *str, int i)
{
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
}
