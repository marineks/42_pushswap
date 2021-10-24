/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:42:16 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/24 13:42:15 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_4num_solver(t_data *data)
{
	t_list *first; 
	t_list *second;
	t_list *third;
	t_list *fourth;

	// On assigne chaque node de la stack de size 4 à sa propre copie
	first = data->stack_a;
	second = first->next;
	third = second->next;
	fourth = third->next;
	
	// Mon algo qui ne met que 6 coups max // edit pour 2 3 1 4 il met 7 coups
	while (check_sorted(data) == FAILURE)
	{
		isolate_lowest_el(data);
		push_b(data);
		apply_3num_solver(data);
		push_a(data);

		first = data->stack_a;
		second = first->next;
		third = second->next;
		fourth = third->next;
	}
}