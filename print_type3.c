/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:20:57 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/10 17:11:39 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_oup(va_list *ap, t_param *param)
{
	param->number++;
	ft_putnbr(va_arg(*ap, unsigned int));
}

void	print_u(va_list *ap, t_param *param)
{
	param->number++;
	ft_putnbr(va_arg(*ap, unsigned int));
}

void	print_uup(va_list *ap, t_param *param)
{
	param->number++;
	ft_putnbr(va_arg(*ap, unsigned int));
}

void	print_x(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_uitoabase(va_arg(*ap, unsigned int), 16);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	ft_strdel(&str);
}

void	print_xup(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_uitoabase(va_arg(*ap, unsigned int), 16);
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		ft_putchar(str[i]);
		param->number++;
		i++;
	}
	ft_strdel(&str);
}
