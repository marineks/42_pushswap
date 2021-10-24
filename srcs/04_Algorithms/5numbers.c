/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:59:47 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/24 14:00:57 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_5num_solver(t_data *data)
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
	fifth = fourth->next;
	
	// Mon algo qui ne met entre 7 et 10 coups max
	while (check_sorted(data) == FAILURE)
	{
		isolate_lowest_el(data);
		push_b(data);
		apply_4num_solver(data);
		push_a(data);

		first = data->stack_a;
		second = first->next;
		third = second->next;
		fourth = third->next;
		fifth = fourth->next;
	}
}