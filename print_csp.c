/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:42:48 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/14 18:06:39 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

void		print_c(va_list *ap, t_param *param)
{
	char	c;

	if (param->l)
	{
		print_cup(ap, param);
		return;
	}
	c = va_arg(*ap, int);
	param_width(param, 1);
	param_zero(param, 1);
	ft_putchar(c);
	param->number++;
	param_minus(param, 1);
}

void		print_cup(va_list *ap, t_param *param)
{
	wchar_t		c;
	int			size;

	c = va_arg(*ap, wchar_t);
	size = whatsize(c);
	param_width(param, size);
	param_zero(param, size);
	print_wchart(c);
	param->number = param->number + size;
	param_minus(param, size);
}

void		print_s(va_list *ap, t_param *param)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	if (param->l)
	{
		print_sup(ap, param);
		return;
	}
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		param->number = param->number + 6;
		return ;
	}
	size = ft_strlen(str);
	param_widthstr(param, size);
	param_zero(param, size);
	if (param->precision == 0)
	{
		while (str[i] != '\0')
		{
			param->number++;
			ft_putchar(str[i]);
			i++;
		}
	}
	else if (param->precision && param->precision >= size)
	{
		while (str[i] != '\0')
		{
			param->number++;
			ft_putchar(str[i]);
			i++;
		}
	}
	else if (param->precision && param->precision < size)
		param_precisionstr(param, str);
	param_minus(param, size);
}

void		print_sup(va_list *ap, t_param *param)
{
	wchar_t		*str;
	int			i;
	int			size;

	i = 0;
	size = 0;
	str = va_arg(*ap, wchar_t*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		param->number = param->number + 6;
		return ;
	}
	while (str[i] != '\0')
	{
		size = size + whatsize(str[i]);
		i++;
	}
	param_widthwchart(param, str, size);
	param_zero(param, size);
	if (param->precision == 0)
	{
		ft_putwchart(str);
		param->number = param->number + size;
	}
	else if (param->precision && param->precision > size)
	{
		ft_putwchart(str);
		param->number = param->number + size;
	}
	else
		param_precisionwchart(param, str, size);
	param_minus(param, size);
}

void		print_p(va_list *ap, t_param *param)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	str = ft_ultoabase(va_arg(*ap, unsigned long), 16);
	size = ft_strlen(str);
	if (param->minus == 0)
		param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param, size);
	ft_putstr("0x");
	param->number = param->number + 2;
	param_zero(param, size);
	param_precision(param, size);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, size);
	ft_strdel(&str);
}
