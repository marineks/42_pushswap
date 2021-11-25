/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:07 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 14:38:22 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>


// Selon l'index/rank envoyé en argument, trouve la valeur qui y correspond.
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

// Vérifie si l'elt en argument est bien tout en haut de la stack
int	is_on_top_of(t_list *stack, long int element)
{
    t_list *tmp;

    tmp = stack;
    if (tmp->number == element)
        return (SUCCESS);
    else
        return (FAILURE);
}