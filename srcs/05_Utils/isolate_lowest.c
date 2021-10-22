/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate_lowest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:40:37 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/22 17:48:13 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	isolate_lowest_el(t_data *data)
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

	if (is_lowest(second->number, first->number, third->number,
		fourth->number) == SUCCESS)
			swap_a(data);
	else if (is_lowest(third->number, second->number, first->number,
		fourth->number) == SUCCESS 
		|| is_lowest(fourth->number, first->number, third->number,
		second->number) == SUCCESS)
	{
		while (is_lowest(first->number, fourth->number, third->number,
		second->number) == FAILURE)
		{
			reverse_a(data);
			first = data->stack_a;
			second = first->next;
			third = second->next;
			fourth = third->next;
		}
	}
}