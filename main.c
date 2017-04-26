/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:10:05 by jcharloi          #+#    #+#             */
/*   Updated: 2017/04/26 19:53:58 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

/*
** %[parameter][flags][width][.precision][length]type
** %  1$         space                            f
** %  2$         0            .*(3eme param->3$)  d
** %  4$         +            .*(3eme param->3$)  d
** %  1$         #      10    .20            l    s
** %  6$         -      50    .              l    x
** -----------------------------------------------------------------------------
** Largeur (buff_size ?) est un entier décimal positif contrôlant le nombre
** minimal de caractères imprimés.
** Si le nombre de caractères (octets) de valeur de sortie est INFERIEUR à la
** largeur, des blancs sont ajoutés sur la gauche ou la droite.
** (selon que le - indicateur) jusqu'à ce que la largeur minimale
** soit atteinte.
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
	ft_printf("-------- TEST DE PRINTF --------\n");
	// ft_printf("------- TEST DES FLAGS --------\n");
	//ft_printf("%1$+100.6d\n", 42);
	// ft_printf("--- TEST DES + ----\n");
	// ft_printf("%+d\n", 0);
	// ft_printf("%+d\n", -4);
	// ft_printf("%+d\n", 42);
	// ft_printf("%+D\n", 5200000L);
	// ft_printf("--- TEST DES -/space ----\n");
	//printf("L'original : %-10.5d\n", 4242);
	//ft_printf("Le mien    : %-10.5d\n", 4242);
	//printf("L'original : %-15p\n", 0);
	//ft_printf("Le mien    : %-15p\n", 0);
	// printf("L'original : %-+10.4d\n", 4242);
	// ft_printf("Le mien    : %-+10.4d\n", 4242);
	// printf("L'original : %-010d\n", 42);
	// ft_printf("Le mien    : %-010d\n", 42);
	// ft_printf("------ TEST DES # -------\n");
	// printf("L'original #o: %#010o\n", 42);
	//printf("L'original #x: %#O\n", 1);
	// printf("L'original #X: %#010X\n", 42);
	// ft_printf("Le mien    #o: %#010o\n", 42);
	// ft_printf("Le mien    #x: %#O\n", 1);
	// ft_printf("Le mien    #X: %#010X\n", 42);
	// printf("L'original : %10d\n", 12);
	// ft_printf("Le mien    : %10d\n", 12);
	// printf("L'original : %010x\n", -42);
	// ft_printf("Le mien    : %010x\n", -42);
	// ft_printf("---- FIN DU TEST DES FLAGS -----\n");
	// ft_printf("-------TEST DES TYPES--------\n");
	// printf("Test des s : %05s\n", "abc");
	// ft_printf("Test des s : %05s\n", "abc");
	// ft_printf("Test des S : %030S\n", L"我是一只猫。");
	//ft_printf("Test des d : %d\n", 2147483647);
	// ft_printf("Test des D : %D\n", LONG_MIN);
	// ft_printf("Test des i : %i\n", 2147483647);
	// ft_printf("Test des o : %o\n", 2147483647);
	// ft_printf("Test des O : %O\n", 2147483647);
	// ft_printf("Test des u : %u\n", 2147483647);
	// ft_printf("Test des U : %U", 42);
	// ft_printf("Test des x : %x\n", -42);
	// ft_printf("Test des X : %X\n", -1);
	//printf("Test des c : %3c\n", 0);
	//ft_printf("Test des c : %3c\n", 0);
	// ft_printf("Test des C : %C\n", L'δ');
	// ft_printf("Test des C : %C\n", L'猫');
	// ft_printf("Test des p : %p\n", &min);
	// ft_printf("----FIN DU TEST DES TYPES-----\n");
	// ft_printf("---- TEST DES PRECISIONS ----\n");
	// printf("L'original : %.4o\n", 42);
	//printf("L'original : %.4u\n", 42);
	// printf("L'original : %0.8d\n", 42);
	setlocale(LC_ALL, "");
	// printf("L'original : %15.6S\n", L"我是一只猫。");
	// printf("L'original : %15.4llo\n", 18446744073709551615);
	// printf("L'original : % 10.5d\n", 2500);
	//printf("L'original : %5.2s is a string\n", "");
	// printf("L'original : %4.15s\n", "I am 42");
	// ft_printf("Le mien    : %15.6S\n", L"我是一只猫。");
	//ft_printf("Le mien    : %.2s is a string\n", "");
	// ft_printf("Le mien    : %15.4llo\n", 18446744073709551615);
	// ft_printf("Le mien    : %4.15s\n", "I am 42");
	//printf("L'original : %0.8d\n", 42);
	// printf("L'original : %2.9p\n", 1234567);
	// printf("L'original : %15.4p\n", 0);
	// printf("L'original : %15.4p\n", 1234);
	// printf("L'original : %4.15p\n", "42");
	// printf("L'original : %4.15p\n", "I am 42");
	// ft_printf("Le mien    : %2.9p\n", 1234567);
	// ft_printf("Le mien    : %15.4p\n", "42");
	// ft_printf("Le mien    : %4.15p\n", "42");
	// ft_printf("Le mien    : %4.15p\n", "I am 42");
	
	// printf("L'original : %15.4d\n", 42);
	// ft_printf("Le mien    : %4.15d\n", 42);
	// ft_printf("Le mien    : %15.4d\n", 42);
	// printf("L'original : %10.d, %10.0d\n", 0, 0);
	//ft_printf("Le mien    : %.4u\n", 42);

	/* 
	** ! Avec le d !
	** Precision (0) : intlen(precision) > intlen(param) = param - precision
	** sinon rien.
	** Width ( ) : intlen(width) > intlen(param) = param - width
	** sinon rien.
	** Precision avec width ( ) (0) : Meme comportement independement de l'autre
	*/

	//ft_printf("L'original : %0.8d\n", 42);
	// ft_printf("---- FIN DU TEST DES PRECISIONS ----\n");
	// ft_printf("---- TEST DES HAUTEURS ----\n");
	// printf("L'original : %o %hd %hho\n", -42, SHRT_MIN, -42);
	// ft_printf("Le mien    : %o %hd %hho\n", -42, SHRT_MIN, -42);
	// printf("L'original : %lc\n", L'ﺡ');
	// ft_printf("Le mien    : %lc\n", L'ﺡ');
	//ft_printf("Le mien    : %hd\n", 42);
	// ft_printf("Le mien    : %lld\n", (unsigned long)INT_MIN - 1);
	ft_printf("-------TEST DES CAS--------\n");
	///   printf("%#llx\n", 9223372036854775807);
	//ft_printf("%#llx\n", 9223372036854775807);
	//printf("%0.o, %0.x\n", 0, 0);
	//printf("%#.d, %#.u\n", 0, 42);
	//ft_printf("ok : %0.o, %0.x\n", 0, 0);
	//ft_printf("ok : %#.d, %#.u\n", 0, 42);
	printf("L'original : o : %.o, %.0o, %#.o, %#.0o, || x : %.x, %.0x, %#.x, %#.0x\n", 0, 0, 42, 42, 0, 0, 0, 0);
	//printf("L'original : %010d\n", 42);
	//printf("L'original : {%-.s}, {%05.s}, {%+5.S}, %#.3o, %#.5x\n", 0, L"42 c est cool", 1);
	//printf("L'original : %#.3o\n", 1);
	//printf("L'original : %#.5O\n", 1);

	/*
	** #/-/0. = écrit l'argument pour o, O, x, X (c, C, d, D, i, s, S, p, u, U sont undefined)
	** . = écrit l'argument pour c, C, p
	** width. = width + écrit l'argument pour c, d, D, i, o, O, p, u, U, x, X
	** les +/#/0 sont undefined avec les s/S
	*/

	ft_printf("Le mien    : o : %.o, %.0o, %#.o, %#.0o, || x : %.x, %.0x, %#.x, %#.0x\n", 0, 0, 42, 42, 0, 0, 0, 0);
	//ft_printf("Le mien    : %#.5O\n", 1);
	//ft_printf("Le mien    : {%-.s}, {%-5.S}, %#.3o, %#.5x\n", 0, L"42 c est cool", 1);
	// ft_printf("Le mien    : %.c\n", 0);
	// ft_printf("Le mien    : %#.O\n", -42);
	// ft_printf("Le mien    : %s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"ﻞﺤﻣ ﺦﻧﺰﻳﺭ");
	// ft_printf("%1$f:%2$10.*3$d:%4$.*3$ld\n", hour, min, precision, (long)sec);
	// printf("Pourquoi ?%*d", hour, min);
	// printf("\n");
	// printf("Pourquoi ?%2$*1$d", hour, min);
	return (0);
}