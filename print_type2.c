/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:19:58 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/10 17:11:36 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(va_list *ap, t_param *param)
{
	param->number++;
	ft_putnbr(va_arg(*ap, int));
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
	param->number++;
	ft_putnbr(va_arg(*ap, long));
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
	param->number++;
	ft_putnbr(va_arg(*ap, unsigned int));
}
