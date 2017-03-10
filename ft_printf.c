/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:34:29 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/10 16:30:56 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isformattype(t_param *param, int c)
{
	const char	*str = "sSpdDioOuUxXcCeEfFgGaAn";
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
		{
			param->type = i;
			return (1);
		}
		i++;
	}
	param->type = -1;
	return (0);
}

static int	check_after(t_param *param, const char *format, int i)
{
	int		o;
	int		size;

	o = i;
	size = 0;
	while (format[i] != '\0' && ft_isformattype(param, format[i]) != 1)
	{
		size++;
		i++;
	}
	param->list_param = ft_strsub(format, o + 1, size);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	t_param	param;
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	param.number = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			param.number++;
		}
		else if (format[i + 1] == '%')
		{
			ft_putchar('%');
			param.number++;
			i++;
		}
		else
		{
			i = check_after(&param, format, i);
			if (param.type >= 0)
				print_type(&param, &ap);
			free(param.list_param);
		}
		i++;
	}
	va_end(ap);
	return (param.number);
}

//Si type vaut 0, pas de parametres apres le %.