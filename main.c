/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:10:05 by jcharloi          #+#    #+#             */
/*   Updated: 2017/03/10 16:28:23 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[parameter][flags][width][.precision][length]type
** %  1$                                          f
** %  2$                      .*(3eme param->3$)  d
** %  4$                      .*(3eme param->3$)  d
** %  1$         #      10    .20            l    s
** %  6$         -      50    .              l    x
** -----------------------------------------------------------------------------
** Largeur (buff_size ?) est un entier décimal positif contrôlant le nombre
** minimal de caractères imprimés.
** Si le nombre de caractères (octets) de valeur de sortie est INFERIEUR à la
** largeur, des blancs sont ajoutés sur la gauche ou la droite.
** (selon que le - indicateur est spécifié) jusqu'à ce que la largeur minimale
** est atteinte.
** Si le nombre de caractères de valeur de sortie est SUPERIEUR, il écrit tout
** et ne tronque pas.
** Pour les types ls et S, la largueur compte en octets mais fait la même chose,
** sauf que c'est en octets.
** -----------------------------------------------------------------------------
** Precision est un entier décimal positif précédé d'une période, qui
** spécifie le nombre de caractères à imprimer ou le nombre de décimales
** (.nombre ou .* n-ième argument).
*/

int		main(int argc, char **argv)
{
	double	hour;
	int		min;
	int		precision;
	int		sec;

	(void)argc;
	(void)argv;
	hour = 15;
	min = 59;
	precision = 10;
	sec = 42;
	while (1)
	{
		// ft_printf("%1$+100.6d\n", 42);
		// ft_printf("-------TEST DES TYPES--------\n");
		ft_printf("Test des s : %s\n", "Charlotte");
		ft_printf("Test des S : %S\n", L"sêjruykxfmxhgmjuyklduc kmgjn");
		ft_printf("Test des d : %d\n", 2147483647);
		// ft_printf("Test des D : %D\n", 2147483647);
		ft_printf("Test des i : %i\n", 2147483647);
		// ft_printf("Test des o : %o\n", 2147483647);
		// ft_printf("Test des O : %O\n", 2147483647);
		// ft_printf("Test des u : %u\n", 2147483647);
		// ft_printf("Test des U : %U\n", 2147483647);
		ft_printf("Test des x : %x\n", -42);
		ft_printf("Test des X : %X\n", -1);
		ft_printf("Test des c : %c\n", 'n');
		ft_printf("Test des C : %C\n", L'é');
		// ft_printf("Test des p : %p\n", &min);
		// ft_printf("----FIN DU TEST DES TYPES-----\n");
		// ft_printf("-------TEST DES CAS--------\n");
		// ft_printf("%% : %%");
		// ft_printf("123%s456\n", "borhink");
		//ft_printf("Je m'appelle %s Roi des Trolls, j'ai %d ans\n", "Rammus", 453);
		//ft_printf("Salut %c, je mange %d oeufs\n", 'o', 42);
		//sec = ft_printf("%d\n", 42000);
		//printf("The %d\n", 1);
		// ft_printf("Je mange %x fruits", 4294967295);
		// ft_printf("%1$f:%2$10.*3$d:%4$.*3$ld\n", hour, min, precision, (long)sec);
		// printf("Pourquoi ?%*d", hour, min);
		// printf("\n");
		// printf("Pourquoi ?%2$*1$d", hour, min);
		// printf("\n");
		// printf("-------------------\n");
		// printf("DOUBLE\n");
		// printf("e : %e\n", hour);
		// printf("f : %f\n", hour);
		// printf("g : %g\n\n", hour);
		// printf("-------------------\n");
		// printf("N\n");
		// printf("0123456789%n\n", &sec);
		// printf("%d\n", sec);
		// printf("-------------------\n");
		// printf("numero : |%10d|\n", 42);
		// printf("\n");
		// printf("-------------------\n");
		// printf("FLAG #\n");
		// printf("hex : %#g\n", hour);
		// ft_printf("----------------\n");
		// ft_printf("ABCAAR\n");
		sleep(10);
	}
	return (0);
}
