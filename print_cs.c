/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:42:48 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/26 19:17:34 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

void			print_c(va_list *ap, t_param *param)
{
	char	c;

	if (param->l)
	{
		print_cup(ap, param);
		return ;
	}
	c = va_arg(*ap, int);
	param->sizestr = 1;
	param_width(param);
	param_zero(param);
	ft_putchar(c);
	param->number++;
	param_minus(param);
}

void			print_cup(va_list *ap, t_param *param)
{
	wchar_t		c;

	c = va_arg(*ap, wchar_t);
	param->sizestr = whatsize(c);
	param_width(param);
	param_zero(param);
	print_wchart(c);
	param->number = param->number + param->sizestr;
	param_minus(param);
}

void			print_s(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	if (param->l)
	{
		print_sup(ap, param);
		return ;
	}
	if ((str = va_arg(*ap, char *)) == NULL)
	{
		ft_putstr("(null)");
		param->number = param->number + 6;
		return ;
	}
	if (check_width(param) == 1)
		return ;
	param->sizestr = ft_strlen(str);
	param_widthstr(param);
	param_zero(param);
	if (param->precision == 0)
		print_arg(param, str, i);
	else if (param->precision && param->precision >= param->sizestr)
		print_arg(param, str, i);
	else if (param->precision && param->precision < param->sizestr)
		param_precisionstr(param, str);
	param_minus(param);
}

static void		print_supagain(t_param *param, wchar_t *str)
{
	param_widthwchart(param, str);
	param_zero(param);
	if (param->precision == 0)
	{
		ft_putwchart(str);
		param->number = param->number + param->sizestr;
	}
	else if (param->precision && param->precision > param->sizestr)
	{
		ft_putwchart(str);
		param->number = param->number + param->sizestr;
	}
	else
		param_precisionwchart(param, str);
	param_minus(param);
}

void			print_sup(va_list *ap, t_param *param)
{
	wchar_t		*str;
	int			i;

	i = 0;
	str = va_arg(*ap, wchar_t*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		param->number = param->number + 6;
		return ;
	}
	if (check_width(param) == 1)
		return ;
	while (str[i] != '\0')
	{
		param->sizestr = param->sizestr + whatsize(str[i]);
		i++;
	}
	print_supagain(param, str);
}
