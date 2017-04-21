/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:34:29 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/20 15:57:53 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_print_type[15] =
{
	print_s,
	print_sup,
	print_p,
	print_d,
	print_dup,
	print_i,
	print_o,
	print_oup,
	print_u,
	print_uup,
	print_x,
	print_xup,
	print_c,
	print_cup,
	print_pourcent
};

void		print_type(t_param *param, va_list *ap)
{
	g_print_type[param->type](ap, param);
}

static int	whenpourcent(t_param *param, va_list *ap, const char *format,
							int *i)
{
	param->plus = 0;
	param->minus = 0;
	param->sharp = 0;
	param->space = 0;
	param->width = 0;
	param->zero = 0;
	param->precision = 0;
	param->isprecision = 0;
	param->h = 0;
	param->hh = 0;
	param->l = 0;
	param->ll = 0;
	param->j = 0;
	param->z = 0;
	param->sizestr = 0;
	check_after(param, format, i);
	if (param->type >= 0)
	{
		if (param->minus != 0 && param->precision != 0)
			param->zero = 0;
		if (param->precision != 0 && param->zero != 0)
			param->zero = 0;
		print_type(param, ap);
	}
	return (0);
}

static void	writeanddo(t_param *param, const char *format, va_list *ap)
{
	int		i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			param->number++;
		}
		else if (whenpourcent(param, ap, format, &i) == 1)
			return ;
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_param	param;
	va_list	ap;

	va_start(ap, format);
	param.number = 0;
	writeanddo(&param, format, &ap);
	va_end(ap);
	return (param.number);
}
