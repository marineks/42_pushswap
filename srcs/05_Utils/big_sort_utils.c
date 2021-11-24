/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:07 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/24 17:19:31 by msanjuan         ###   ########.fr       */
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
int	is_on_top_of(t_list *stack, long int element)
{
    t_list *tmp;

    // printf("n'est pas en haut de la stack : \n");
    tmp = stack;
    if (tmp->number == element)
        return (SUCCESS);
    else
        return (FAILURE);
}