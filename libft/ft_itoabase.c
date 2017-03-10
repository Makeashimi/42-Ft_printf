/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:02:24 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/10 16:55:38 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_taille(int n, int base)
{
	int compteur;

	compteur = 0;
	if (n == 0)
		compteur++;
	else if (base == 10 && n < 0)
		compteur++;
	while (n != 0)
	{
		n = n / base;
		compteur++;
	}
	return (compteur);
}

char		*ft_itoabase(int n, int base)
{
	const char	*str = "0123456789abcdef";
	char		*fraiche;
	long		nb;
	int			taille;
	int			i;

	nb = (long)n;
	taille = ft_taille(n, base);
	i = taille - 1;
	if (!(fraiche = ft_strnew(taille)))
		return (NULL);
	if (n < 0)
	{
		nb = nb * -1;
		if (base == 10)
			fraiche[0] = '-';
	}
	while (nb >= base)
	{
		fraiche[i] = str[nb % base];
		nb = nb / base;
		i--;
	}
	fraiche[i] = str[nb];
	return (fraiche);
}
