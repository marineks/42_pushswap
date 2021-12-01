/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:11:57 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/01 12:07:53 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../includes/pushswap.h"
/*

Le checker doit prendre en argument la série de nombres à trier donc reprendre 
son format list et le mettre dans une liste chainée

Le 1er arg doit etre en haut de la liste (normalement cest deja le cas avec mon 
code)

Si pas d'arg le checker s'arrete

______

Boucle while(1) pour que le checker attendre que l'on mette des instructions

Mettre un "/n" entre les instructions
Quand toutes les instructions ont ete lu, on execute.

/  peut etre faire :
while (nb_de_coups--)
{
    execute(arg_recu)
}


et execute(char* arg_recu)
{
    GERER LES ERREURS ET METTRE RETOUR SUR 2 (STANDARD ERROR)
    si arg_recu == RA, faire rotate
    etc
    etc
}

et à la fin : 
if (check_sorted(stack_a) == SUCCESS)
    display "OK"
else
    "KO"

*/

void coucou(void)
{
    ft_putstr_fd("coucou\n", 1);
}