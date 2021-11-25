/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 15:40:39 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

void rra_or_ra(t_data* data, t_list *tmp)
{
    while (STACK_A->number != tmp->number)
    {  
        if (find_index(tmp, tmp->number) > ft_lstsize(STACK_A)/2)
            reverse_a(data);
        else
            rotate_a(data);
    }
}

void    push_chunk_to_B(t_data *data, int limit)
{
    int i;
    t_list *tmp;
    t_list *further;

    tmp = STACK_A;
    i = 1;
    while (i <= data->len_a) 
    {
        further = STACK_A->next;
        if (tmp->number <= limit)
        {
            rra_or_ra(data, tmp);
            push_b(data);
            tmp = STACK_A; 
        }
        else if (further->number <= limit)
        {
            swap_a(data);
            tmp = further->next;
            push_b(data);
        }
        else
            tmp = tmp->next;
        i++;
    }
}

// Trier la stack A en cherchant le smallest number to put on top of stack A
void    sort_last_chunk(t_data *data)
{
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
}

void    push_everything_back_to_A(t_data *data)
{
    long int    biggest_nbr;

    while (STACK_B)
    {
        biggest_nbr = find_max(STACK_B);
        while (is_on_top_of(STACK_B, biggest_nbr) == FAILURE)
        {
            if (find_index(STACK_B, biggest_nbr) > ft_lstsize(STACK_B)/2)
                reverse_b(data);
            else
                rotate_b(data);
        }
        push_a(data);
    }
}

void	apply_big_num_solver(t_data *data, int nbr)
{
    int count;
     
    count = 1;
    TOTAL_SIZE = ft_lstsize(COPY);
    sort_copy(COPY);

    while (count < nbr)
    {
        CHUNK = find_value(COPY, (TOTAL_SIZE/nbr * count));
        push_chunk_to_B(data, CHUNK);
        count++;
    }
    sort_last_chunk(data);
    push_everything_back_to_A(data);
}  
