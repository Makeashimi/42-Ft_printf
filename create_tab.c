/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:23:19 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/10 17:11:20 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_print_type[14] =
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
	print_cup
};

void	print_type(t_param *param, va_list *ap)
{
	g_print_type[param->type](ap, param);
}
