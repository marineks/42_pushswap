/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/23 20:17:54 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

// Selon la valeur Rank envoyée en argument, trouve le nb pour 1/4 1/2 3/4.
int		find_value(t_list *stack, int which_rank)
{
	t_list 		*tmp;
    int         searched_value;
    int         i;
	
	tmp = stack;
    i = 1;

    while (i <= which_rank)
    {
        tmp = tmp->next;
        i++;
    }
    searched_value = tmp->number;
	return (searched_value);
}

// Vérifie si la stack A contient toujrs des élts en dessous ou égal à la limite
int		contains_els_below(t_data *data, int limit)
{
	t_list *tmp;

	tmp = data->stack_a;
	while (tmp != NULL)
	{
		if (tmp->number <= limit) 
			return (SUCCESS);
		tmp = tmp->next;
	}
	return (FAILURE);
}

// Vérifie si l'elt en argument est bien tout en haut de la stack
int	is_on_top_of_stack(t_data *data, int element)
{
    t_list *tmp;

    // printf("n'est pas en haut de la stack : \n");
    tmp = STACK_A;
    if (tmp->number == element)
        return (SUCCESS);
    else
        return (FAILURE);
}	

void	apply_big_num_solver(t_data *data)
{

    t_list *tmp;
    t_list * last;

    tmp = STACK_A;
    last = ft_lstlast(STACK_A);
    // TRIE LA COPIE DE STACK A
    sort_copy(COPY);

    // TROUVER LES VALEURS POUR MES QUARTILES ET MEDIANE
    QUARTER = find_value(COPY, (ft_lstsize(COPY)/4));
	MEDIANE = find_value(COPY, QUARTER * 2);
    THREE_QUARTERS = find_value(COPY, QUARTER * 3);
    printf("1/4: %d | Valeur à ce rang: %d\n", (ft_lstsize(COPY)/4), QUARTER);
    printf("Médiane: %d | Valeur à ce rang: %d\n", (QUARTER * 2), MEDIANE);
    printf("3/4: %d | Valeur à ce rang: %d\n", (QUARTER * 3), THREE_QUARTERS);

    // PUSH TOUS LES NBS EN DESSOUS DE QUARTER DANS B

    // while (STACK_A != last)
    while (contains_els_below(data, QUARTER) == SUCCESS) 
    {
        if (STACK_A && STACK_A->number <= QUARTER)
        {
            while (is_on_top_of_stack(data, STACK_A->number) == FAILURE)
            {
               
                if (find_index(STACK_A, STACK_A->number) > find_avg_index(data))
                    reverse_a(data);
                else
                    rotate_a(data);
            }
            push_b(data); 
        }
        else
            rotate_a(data);
    }
	display_stack(data, 'A');
	display_stack(data, 'B');
}  

//  printf("le nombre %ld ", tmp->number);

// if (STACK_A->number <= QUARTER)
//     push_b(data);
// else
//     rotate_a(data);

// tmp = tmp->next;