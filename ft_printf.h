/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:34:59 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/11 17:56:05 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef	struct	s_param
{
	char		*list_param;
	int			type;
	int			number;
}				t_param;

typedef	void(*t_arg)(va_list*, t_param*);

int				ft_printf(const char *format, ...);
void			print_s(va_list *ap, t_param *param);
void			print_sup(va_list *ap, t_param *param);
void			print_p(va_list *ap, t_param *param);
void			print_d(va_list *ap, t_param *param);
void			print_dup(va_list *ap, t_param *param);
void			print_i(va_list *ap, t_param *param);
void			print_o(va_list *ap, t_param *param);
void			print_oup(va_list *ap, t_param *param);
void			print_u(va_list *ap, t_param *param);
void			print_uup(va_list *ap, t_param *param);
void			print_x(va_list *ap, t_param *param);
void			print_xup(va_list *ap, t_param *param);
void			print_c(va_list *ap, t_param *param);
void			print_cup(va_list *ap, t_param *param);
void			print_type(t_param *param, va_list *ap);

#endif
