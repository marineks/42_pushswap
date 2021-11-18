/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_and_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:26:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/18 18:21:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>
/*
*/


void apply_big_num_solver(t_data *data)
{
	sort_stack_a(data->stack_a, find_lowest(data->stack_a), find_max(data))
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