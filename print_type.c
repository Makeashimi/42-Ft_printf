/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:42:48 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/11 14:07:40 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** base2	00	01	10	11  100	101	110 111							"01"
** base10	00	01	02	03	04	05	06	07	08	09	10	11	12	13 "0123456789"
** base16	0 1 2 3 4 5 6 7 8 9 a b c d e f 10 11 12 13 14 15 16 17 18 19 1a
** "0123456789abcdef"
*/

#include "ft_printf.h"
#include <wchar.h>

static int	print_wchart(wchar_t c)
{
	if (c >= 1114112)
		return (0);
	if (c < 128)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c < 2048)
	{
		ft_putchar(192 | (c >> 6));
		ft_putchar(128 | (c & 63));
		return (2);
	}
	else if (c < 65536)
	{
		ft_putchar(224 | (c >> 12));
		ft_putchar(128 | ((c >> 6) & 63));
		ft_putchar(128 | (c & 63));
		return (3);
	}
	ft_putchar(240 | (c >> 18));
	ft_putchar(128 | ((c >> 12) & 63));
	ft_putchar(128 | ((c >> 6) & 63));
	ft_putchar(128 | (c & 63));
	return (4);
}

void		print_s(va_list *ap, t_param *param)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		param->number = param->number + 6;
		return ;
	}
	while (str[i] != '\0')
	{
		param->number++;
		ft_putchar(str[i]);
		i++;
	}
}

void		print_sup(va_list *ap, t_param *param)
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
	while (str[i] != '\0')
	{
		param->number = param->number + print_wchart(str[i]);
		i++;
	}
}

void		print_c(va_list *ap, t_param *param)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar(c);
	param->number++;
}

void		print_cup(va_list *ap, t_param *param)
{
	wchar_t		c;

	c = va_arg(*ap, wchar_t);
	param->number = param->number + print_wchart(c);
}
