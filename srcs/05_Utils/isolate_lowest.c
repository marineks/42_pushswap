/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate_lowest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:40:37 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/23 21:10:18 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

// But de cette function : Vérifie que le nb sélectionné est bien le 1er node
int		is_lowest(t_data *data, long int compared)
{
	t_list *tmp;
	
	tmp = data->stack_a;

	while (tmp != NULL)
	{
		if (compared > tmp->number) // on s'en moque s'il croise son dupe car ce sera == et non >
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

void	isolate_smallest(t_data *data)
{
	t_list *tmp;
	long int first_el;
	
	tmp = data->stack_a;
	first_el = tmp->number;
	if (find_index(data->stack_a, find_lowest(data->stack_a)) > find_avg_index(data, STACK_A))
	{
		while (is_lowest(data, first_el) == FAILURE)
		{
			reverse_a(data);
			tmp = data->stack_a;
			first_el = tmp->number;
		}
	} 
	else
	{
		while (is_lowest(data, first_el) == FAILURE)
		{
			rotate_a(data);
			tmp = data->stack_a;
			first_el = tmp->number;
		}
	}
}
