/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_and_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:26:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/24 13:34:16 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

/*
*/

int contains_elts_below_mediane(t_list *stack, long int mediane)
{
	t_list *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->number >= mediane)
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

void	balance_prev_rotate(t_data *data, int count, char *str)
{
	int i;

	i = 0;
	printf("Count de RA: %d\n", count);
	if (!count)
		return ;
	while (i < count)
	{
		if (ft_strncmp(str, "ra", ft_strlen(str)) == 0)
			reverse_a(data);
		else
			reverse_b(data);
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
	// mediane = find_mediane(data->stack_b);
	mediane = (min + max) / 2;
	while (contains_elts_below_mediane(tmp, mediane) == FAILURE) // while stack_a contains elts lower than or equal to mediane
	{
		if (tmp->number < mediane)
		{
			rotate_b(data);
			count++;
		}
		else
			push_a(data);
		tmp = tmp->next;
	}
	// balance_prev_rotate(data, count, "rb");
	sort_stack_a(data, mediane, max);
	// sort_stack_b(data, min, mediane - 1);
}

void	sort_stack_a(t_data *data, long int min, long int max)
{
	t_list		*tmp;
	long int	mediane;
	int			count;

	if (min >= max)
		return;

	count = 0;
	tmp = data->stack_a;
	// mediane = find_mediane(data->stack_a);
	display_stack(data, 'A');
	display_stack(data, 'B');

	mediane = (min + max) / 2;
	while (contains_elts_below_mediane(tmp, mediane) == FAILURE) // while stack_a contains elts lower than or equal to mediane
	{
		if (tmp->number > mediane)
		{
			rotate_a(data);
			count++;

		}
		else
			push_b(data);
		display_stack(data, 'A');
		display_stack(data, 'B');
		tmp = tmp->next;
	}
	// balance_prev_rotate(data, count, "ra");
	
	sort_stack_a(data, mediane + 1, max);
	// sort_stack_b(data, min, mediane);
}

// void apply_big_num_solver(t_data *data)
// {
// 	sort_stack_a(data, find_lowest(data->stack_a), find_max(data->stack_a));
// 	display_stack(data, 'A');
// 	display_stack(data, 'B');
// }


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