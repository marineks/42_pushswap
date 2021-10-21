/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:15:44 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/21 17:14:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/* 
	Par principe, vu que l'on teste en amont si la string est déjà ordonnée
	Cela veut dire que la stack se présente actuellement sous cette forme:
	< ./pushswap PLUS_GRAND_NOMBRE PETIT_NOMBRE >
	Il suffit donc de rotate la stack pour inverser les deux nombres.
*/

void	apply_3num_solver(t_data *data)
{
	t_list *first_elt; 
	t_list *second_elt;
	t_list *third_elt;

	// On assigne chaque node de la stack de size 3 à sa propre copie
	first_elt = data->stack_a;
	second_elt = first_elt->next;
	third_elt = second_elt->next;
	
	// Le hardcode des enfers
	if (first_elt->number < second_elt->number)
	{
		if (first_elt->number < third_elt->number)
		{
			push_b(data);
			rotate_a(data);
			push_a(data);
		}
		else
			reverse_a(data);
	}
	else if (first_elt->number > second_elt->number)
	{
		if (first_elt->number < third_elt->number)
			swap_a(data);
		else
			rotate_a(data);
	}
	else
	{
		swap_a(data);
		reverse_a(data);
	}
}