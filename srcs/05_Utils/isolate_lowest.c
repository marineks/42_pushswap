/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate_lowest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:40:37 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 12:54:54 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
	This function checks if the selected number ("compared") is a) the smallest
	b) on top of the stack.
*/

int	is_lowest(t_data *data, long int compared)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (tmp != NULL)
	{
		if (compared > tmp->number)
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

/*
	This function seeks to push the smallest number of on top of the stack,
	 by using either the RA or RRA operations.
*/

void	isolate_smallest(t_data *data)
{
	t_list		*tmp;
	long int	first_el;
	int			mid;

	tmp = data->stack_a;
	first_el = tmp->number;
	mid = ft_lstsize(data->stack_a) / 2;
	if (find_index(data->stack_a, find_lowest(data->stack_a)) > mid)
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
