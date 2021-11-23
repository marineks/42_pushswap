/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/23 21:20:37 by msanjuan         ###   ########.fr       */
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
int	is_on_top_of(t_list *stack, int element)
{
    t_list *tmp;

    // printf("n'est pas en haut de la stack : \n");
    tmp = stack;
    if (tmp->number == element)
        return (SUCCESS);
    else
        return (FAILURE);
}

void	apply_big_num_solver(t_data *data)
{
    // TRIE LA COPIE DE STACK A
    sort_copy(COPY);

    // TROUVER LES VALEURS POUR MES QUARTILES ET MEDIANE
    QUARTER = find_value(COPY, (ft_lstsize(COPY)/4));
	MIDDLE = find_value(COPY, QUARTER * 2) - 1;
    THREE_QUARTERS = find_value(COPY, QUARTER * 3) - 1;
    printf("1/4: %d | Valeur à ce rang: %d\n", (ft_lstsize(COPY)/4), QUARTER);
    printf("2/4: %d | Valeur à ce rang: %d\n", (QUARTER * 2), MIDDLE);
    printf("3/4: %d | Valeur à ce rang: %d\n", (QUARTER * 3), THREE_QUARTERS);

    // return ;
    // PUSH TOUS LES NBS EN DESSOUS DE QUARTER DANS B
    while (contains_els_below(data, QUARTER) == SUCCESS) 
    {
        if (STACK_A && STACK_A->number <= QUARTER)
        {
            while (is_on_top_of(STACK_A, STACK_A->number) == FAILURE)
            {
                if (find_index(STACK_A, STACK_A->number) > find_avg_index(data, STACK_A))
                    reverse_a(data);
                else
                    rotate_a(data);
            }
            push_b(data); 
        }
        else
            rotate_a(data);
    }
	// display_stack(data, 'A');
	// display_stack(data, 'B');

    // PUSH TOUS LES NBS EN DESSOUS DE MIDDLE DANS B
    while (contains_els_below(data, MIDDLE) == SUCCESS) 
    {
        if (STACK_A && STACK_A->number <= MIDDLE)
        {
            while (is_on_top_of(STACK_A, STACK_A->number) == FAILURE)
            {
                if (find_index(STACK_A, STACK_A->number) > find_avg_index(data, STACK_A))
                    reverse_a(data);
                else
                    rotate_a(data);
            }
            push_b(data); 
        }
        else
            rotate_a(data);
    }
	// display_stack(data, 'A');
	// display_stack(data, 'B');

    // PUSH TOUS LES NBS EN DESSOUS DE TROIS QUARTS DANS B
     while (contains_els_below(data, THREE_QUARTERS) == SUCCESS) 
    {
        if (STACK_A && STACK_A->number <= THREE_QUARTERS)
        {
            while (is_on_top_of(STACK_A, STACK_A->number) == FAILURE)
            {
                if (find_index(STACK_A, STACK_A->number) > find_avg_index(data, STACK_A))
                    reverse_a(data);
                else
                    rotate_a(data);
            }
            push_b(data); 
        }
        else
            rotate_a(data);
    }
	// display_stack(data, 'A');
	// display_stack(data, 'B');

    // Trier la stack A en cherchant le smallest number to put on top of stack A
    while (check_sorted(data) == FAILURE)
    {
        isolate_smallest(data);
    }
    // display_stack(data, 'A');
	// display_stack(data, 'B');

    // Ici, on push toute la B dans la A en selectionnant le biggest number
    // int count = 0;
    
    while (STACK_B)
    {
        if (STACK_B->number == find_max(STACK_B))
        {
            while (is_on_top_of(STACK_B, STACK_B->number) == FAILURE)
            {
                if (find_index(STACK_B, STACK_B->number) > find_avg_index(data, STACK_B))
                    reverse_b(data);
                else
                    rotate_b(data);
            }
            push_a(data); 
        }
        else
        {
            rotate_b(data);
        }
    }
    // display_stack(data, 'A');
	// display_stack(data, 'B');
}  

//  printf("le nombre %ld ", tmp->number);

// if (STACK_A->number <= QUARTER)
//     push_b(data);
// else
//     rotate_a(data);

// tmp = tmp->next;