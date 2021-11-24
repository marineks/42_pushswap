/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:24:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/24 18:00:49 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_algorithm(int size_of_stack_a, t_data *data)
{
	if (size_of_stack_a == 2)
		apply_2num_solver(data);
	else if (size_of_stack_a == 3)
		apply_3num_solver(data);
	else if (size_of_stack_a == 4)
		apply_4num_solver(data);
	else if (size_of_stack_a == 5)
		apply_5num_solver(data);
	else if (size_of_stack_a <= 100)
		apply_big_num_solver(data);
	else
		apply_big_big_num_solver(data);
}


void	apply_big_num_solver(t_data *data)
{   
	long int    biggest_nbr;
    TOTAL_SIZE = ft_lstsize(COPY);
    
    sort_copy(COPY);
    ONE = find_value(COPY, (TOTAL_SIZE/8));
	TWO = find_value(COPY, (TOTAL_SIZE/7));
	THIRD = find_value(COPY, (TOTAL_SIZE/8));
	FOUR = find_value(COPY, (TOTAL_SIZE/8));
	FIVE = find_value(COPY, (TOTAL_SIZE/8));
	SIX = find_value(COPY, (TOTAL_SIZE/8));
	SEVEN = find_value(COPY, TOTAL_SIZE/2);
    EIGHT = find_value(COPY, TOTAL_SIZE - TOTAL_SIZE/4);
    
    push_chunk_to_B(data, QUARTER);
    push_chunk_to_B(data, MIDDLE);
    push_chunk_to_B(data, THREE_QUARTERS);
    
   
    while (STACK_A)
	{
		isolate_smallest(data);
        push_b(data);
		if (data->len_a == 5)
		{
			apply_algorithm(data->len_a, data);
			push_a(data);
			if (check_sorted(data) == FAILURE)
				swap_a(data);
            break;
		}	
	}
   
    while (STACK_B)
    {
        biggest_nbr = find_max(STACK_B);
       
        
        while (is_on_top_of(STACK_B, biggest_nbr) == FAILURE)
        {
            if (find_index(STACK_B, biggest_nbr) > find_avg_index(data, STACK_B))
                reverse_b(data);
            else
                rotate_b(data);
        }
        push_a(data);
    }

}  