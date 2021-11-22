/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/22 15:19:41 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

// CREER UNE COPIE DE STACK A ET LA TRIER : v

int find_value(t_list *stack, int which_rank)
{
	t_list 		*tmp;
    int         searched_value;
    int         i;
	
	tmp = stack;
    i = 0;

    while (i < which_rank)
    {
        tmp = tmp->next;
        i++;
    }
    searched_value = tmp->number;
	return (searched_value);
}

int contains_els_below(t_data *data, int limit)
{
	t_list *tmp;

	tmp = data->stack_a;
	while (tmp != NULL)
	{
		if (tmp->number <= limit) // Dés qu'on trouve un nb en dessous ou égal à la limite c'est bon
			return (SUCCESS);
		tmp = tmp->next;
	}
	return (FAILURE);
}

void apply_big_num_solver(t_data *data)
{
    // TRIE LA COPIE DE STACK A
    sort_copy(data->copy_stack_a);

    // TROUVER LES VALEURS POUR MES QUARTILES ET MEDIANE
    QUARTER = find_value(data->copy_stack_a, (ft_lstsize(data->copy_stack_a)/4));
	MEDIANE = find_value(data->copy_stack_a, QUARTER * 2);
    THREE_QUARTERS = find_value(data->copy_stack_a, QUARTER * 3);
    printf("1/4: %d | Valeur à ce rang: %d\n", (ft_lstsize(data->copy_stack_a)/4), QUARTER);
    printf("Médiane: %d | Valeur à ce rang: %d\n", (QUARTER * 2), MEDIANE);
    printf("3/4: %d | Valeur à ce rang: %d\n", (QUARTER * 3), THREE_QUARTERS);


    // PUSH TOUS LES NBS EN DESSOUS DE QUARTER DANS B
    while (contains_els_below(data, QUARTER) == SUCCESS) // Tant que la stack_a contient des nombres en dessous du/ égal à QUARTER
    {
        if (data->stack_a->number <= QUARTER)
        {
            if (find_index(data->stack_a, STACK_A->number) > find_avg_index(data))
            {
                while () // tant que cet elt n'est pas tout en haut
                {
                    reverse_a(data);
                }
            }
            else
            {
                while () // tant que cet elt n'est pas tout en haut
                {
                    reverse_a(data);
                }
            }
            push_b(data);
        }
    }
	display_stack(data, 'A');
    printf("toujours la\n");
	display_stack(data, 'B');
}