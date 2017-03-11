/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:19:58 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/11 17:56:46 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_ultoabase(va_arg(*ap, unsigned long), 16);
	write(1, "0x", 2);
	param->number = param->number + 2;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	ft_strdel(&str);
}

void	print_d(va_list *ap, t_param *param)
{
	int		n;

	n = va_arg(*ap, int);
	param->number = param->number + ft_intlen(n);
	ft_putnbr(n);
}

void	print_dup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_ltoabase(va_arg(*ap, long int), 10);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	ft_strdel(&str);
}

void	print_i(va_list *ap, t_param *param)
{
	int		n;

	n = va_arg(*ap, int);
	param->number = param->number + ft_intlen(n);
	ft_putnbr(n);
}

void	print_o(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_uitoabase(va_arg(*ap, unsigned int), 8);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	ft_strdel(&str);
}
