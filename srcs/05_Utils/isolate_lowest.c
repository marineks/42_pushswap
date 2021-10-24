/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate_lowest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:40:37 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/24 13:55:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	isolate_lowest_el(t_data *data)
{
	t_list *first; 
	t_list *second;
	t_list *third;
	t_list *fourth;
	t_list *fifth;

	// On assigne chaque node de la stack de size 4 à sa propre copie
	first = data->stack_a;
	second = first->next;
	third = second->next;
	fourth = third->next;
	if (data->len_a == 5)
		fifth = fourth->next;
	else 
		fifth = NULL;

	if (is_lowest(data, first->number) == SUCCESS)
		return ; // on ne fait rien car le premier elt est deja bien place pour etre isole
	if (is_lowest(data, second->number) == SUCCESS)
			swap_a(data);
	else
	{
		while (is_lowest(data, first->number) == FAILURE)
		{
			reverse_a(data);
			first = data->stack_a;
			second = first->next;
			third = second->next;
			fourth = third->next;
			if (fifth)
				fifth = fourth->next;
		}
	}
}

// Notes : trouver le moyen d'automatiser cette function car la elle n'est codée 
// que pour des listes de 4 nodes