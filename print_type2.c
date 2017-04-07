/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:19:58 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/07 17:08:23 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_d2(t_param *param, int size, char *str, int i)
{
	if ((param->zero && param->space))
		size++;
	//printf("size : %d\n", size);
	param_precisioninteger(param);
	param_zero(param, size);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, size);
	ft_strdel(&str);
}

void		print_d(va_list *ap, t_param *param)
{
	char	*str;
	int		n;
	int		i;
	int		size;

	i = 0;
	n = va_arg(*ap, int);
	str = ft_itoa(n);
	size = ft_strlen(str);
	param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	//printf("size : %d\n", size);
	if (param->plus && (n >= 0 || param->zero == 0))
		size++;
	param_plus(param, n);
	if (n >= 0)
		param_space(param);
	if (param->precision && str[i] == '-')
	 	param->precision++;
	//printf("width : %d\n", param->width);
	param_width(param, size);
	if (str[i] == '-')
	{
		ft_putchar('-');
		param->number++;
		i++;
	}
	print_d2(param, size, str, i);
}

void		print_dup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;
	long	n;

	i = 0;
	n = va_arg(*ap, long);
	str = ft_ltoabase(n, 10);
	param_plus(param, n);
	if (n >= 0)
		param_space(param);
	param_width(param, ft_llen(n));
	param_zero(param, ft_llen(n));
	if (param->plus && n >= 0)
	{
		ft_putchar('+');
		param->number++;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, ft_llen(n));
	ft_strdel(&str);
}

void		print_i(va_list *ap, t_param *param)
{
	print_d(ap, param);
}

void		print_o(va_list *ap, t_param *param)
{
	char			*str;
	unsigned int	nb;
	int				i;
	int				size;

	i = 0;
	nb = va_arg(*ap, unsigned int);
	str = ft_uitoabase(nb, 8);
	size = ft_strlen(str);
	param->precision = param->precision - size;
	if (param->precision < 0)
		param->precision = 0;
	param_width(param, size);
	param_precisioninteger(param);
	if (param->sharp && nb > 0)
	{
		ft_putchar('0');
		param->number++;
	}
	param_zero(param, size);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	param_minus(param, size);
	ft_strdel(&str);
}
