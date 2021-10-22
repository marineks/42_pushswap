/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:15:44 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/22 14:05:43 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_3num_solver(t_data *data)
{
	t_list *first_elt; 
	t_list *second_elt;
	t_list *third_elt;

	// On assigne chaque node de la stack de size 3 à sa propre copie
	first_elt = data->stack_a;
	second_elt = first_elt->next;
	third_elt = second_elt->next;
	
	// Algo qui ne met que 3 coups max
	while (check_sorted(data) == FAILURE)
	{
		if (third_elt->number > first_elt->number 
			&& third_elt->number > second_elt->number)
			swap_a(data);
		else 
			reverse_a(data);
		first_elt = data->stack_a;
		second_elt = first_elt->next;
		third_elt = second_elt->next;
	}
}


	// Le hardcode des enfers
	// if (first_elt->number < second_elt->number)
	// {
	// 	if (first_elt->number < third_elt->number)
	// 	{
	// 		push_b(data);
	// 		rotate_a(data);
	// 		push_a(data);
	// 	}
	// 	else
	// 		reverse_a(data);
	// }
	// else if (first_elt->number > second_elt->number)
	// {
	// 	if (first_elt->number < third_elt->number)
	// 		swap_a(data);
	// 	else
	// 		rotate_a(data);
	// }
	// else
	// {
	// 	swap_a(data);
	// 	reverse_a(data);
	// }

	// Facon de faire avec un peu plus de réflexion, mais par contre plus de coups
	// while (check_sorted(data) == FAILURE)
	// {
	// 	if (first_elt->number < second_elt->number)
	// 	{
	// 		push_b(data);
	// 		rotate_a(data);
	// 		push_a(data);
	// 	}
	// 	if (first_elt->number > second_elt->number)
	// 		swap_a(data);
	// 	first_elt = data->stack_a;
	// 	second_elt = first_elt->next;
	// 	third_elt = second_elt->next;
	// }