/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:08:21 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/18 18:42:48 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>
/*
    Comment calculer une mediane:
    Trier la suite de nombre dans l'ordre croissant
    Obtenir l'index de la médiane
        Trouver l'effectif total (nombre de valeurs)
        Ajouter 1 à l'effectif total et diviser par 2
    La médiane est la valeur trouvée à cet index
*/

t_list *sort_copy(t_list *stack)
{
    t_list      *one_step_further;
    t_list      *head;
	int	temp;

	head = stack;
    one_step_further = stack->next;
    while (stack != NULL)
    {
        one_step_further = stack->next;
    
        while (one_step_further != NULL)
        {
            if (stack->number > one_step_further->number)
            {
                temp = stack->number;
                stack->number = one_step_further->number;
                one_step_further->number = temp;
            }
            one_step_further = one_step_further->next;
        } 
        stack = stack->next;
    }
    return (head);
}

long int find_mediane(t_list *stack)
{
	t_list 		*tmp;
    t_list      *copie;
	long int	mediane;
    int mediane_rank;
    int i;
	
	tmp = stack;
    copie = sort_copy(tmp);
    mediane_rank = (ft_lstsize(stack) + 1)/2;
    i = 1;

    while (i < mediane_rank)
    {
        tmp = tmp->next;
        i++;
    }
    mediane = tmp->number;
	return (mediane);
}

// TESTS FAITS
/*
    Liste : 48 0 -22 3 6 142 20
    Rang de mediane : 4
    Liste dans l'ordre : -22 0 3 6 20 48 142
    A la 4e place de la liste, on a 6 => ca marche!


    Liste : 5000 20 2 -5462 3 1
    Rang : 6 + 1 / 2 = 3.5
    Liste dans l'ordre : -5462 1 2 3 20 5000
    Mediane : 2 ou 3

    Liste : 1 9 2 8 3 7 4 5 6
*/