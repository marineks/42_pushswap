/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_and_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:26:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/18 19:07:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

/*
*/

void	balance_prev_rotate(t_data *data, int count, char *str)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (str == "ra")
			rotate_a(data);
		else
			rotate_b(data);
		i++;
	}
}

void	sort_stack_b(t_data *data, long int min, long int max)
{
	t_list *tmp;
	long int mediane;
	int count;

	if (min > max)
		return;
	count = 0;
	tmp = data->stack_b;
	mediane = find_mediane(data->stack_b);
	while (1) // while stack_a contains elts lower than or equal to mediane
	{
		if (tmp->number > mediane)
		{
			rotate_b(data);
			count++;
		}
		else
			push_a(data);
		tmp = tmp->next;
	}
	balance_prev_rotate(data, count, "rb");
	sort_stack_a(data, mediane, max);
	sort_stack_b(data, min, mediane - 1);
}

void	sort_stack_a(t_data *data, long int min, long int max)
{
	t_list *tmp;
	long int mediane;
	int count;

	if (min >= max)
		return;
	count = 0;
	tmp = data->stack_a;
	mediane = find_mediane(data->stack_a);
	while (1) // while stack_a contains elts lower than or equal to mediane
	{
		if (tmp->number > mediane)
		{
			rotate_a(data);
			count++;
		}
		else
			push_b(data);
		tmp = tmp->next;
	}
	balance_prev_rotate(data, count, "ra");
	sort_stack_a(data, mediane + 1, max);
	sort_stack_b(data, min, mediane);
}

void apply_big_num_solver(t_data *data)
{
	sort_stack_a(data, find_lowest(data->stack_a), find_max(data->stack_a));

}


// PREMIERE VERSION DU SCHLAG
// while (check_sorted(data) == FAILURE)
	// {
	// 	isolate_smallest(data);
	// 	if (data->len_a == 5)
	// 	{
	// 		apply_algorithm(data->len_a, data);
	// 		push_a(data);
	// 		if (check_sorted(data) == FAILURE)
	// 			swap_a(data);
	// 		while (data->len_b > 0)
	// 			push_a(data);
	// 	}	
	// }