/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:09:41 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/10 16:52:10 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_taille(unsigned int n, int base)
{
	int compteur;

	compteur = 0;
	if (n == 0)
		compteur++;
	while (n != 0)
	{
		n = n / base;
		compteur++;
	}
	return (compteur);
}

char		*ft_uitoabase(unsigned int nb, unsigned int base)
{
	const char	*str = "0123456789abcdef";
	char		*fraiche;
	int			taille;
	int			i;

	taille = ft_taille(nb, base);
	i = taille - 1;
	fraiche = ft_strnew(taille);
	if (fraiche == NULL)
		return (NULL);
	while (nb >= base)
	{
		fraiche[i] = str[nb % base];
		nb = nb / base;
		i--;
	}
	fraiche[i] = str[nb];
	return (fraiche);
}
