/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:15:44 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 14:46:43 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
	Le principe ici est de mettre le plus grand nombre en bout de liste.
	Exemple: ./push_swap 2 3 1
	Ici, on va utiliser un RRA pour décaler le 3.
	Exemple: ./push_swap 2 1 3
	Lorsque le plus grand nombre est "au fond" il suffit juste de faire un swap SA
	Exemple: ./push_swap 1 2 3
*/

void	apply_3num_solver(t_data *data)
{
	t_list *first_elt; 
	t_list *second_elt;
	t_list *third_elt;

	first_elt = data->stack_a;
	second_elt = first_elt->next;
	third_elt = second_elt->next;
	
	while (check_sorted(data) == FAILURE)
	{
		if (third_elt->number > first_elt->number 
			&& third_elt->number > second_elt->number)
			swap_a(data);
		else if (first_elt->number > third_elt->number 
			&& first_elt->number > second_elt->number)
			rotate_a(data);
		else
			reverse_a(data);
		first_elt = data->stack_a;
		second_elt = first_elt->next;
		third_elt = second_elt->next;
	}
}
