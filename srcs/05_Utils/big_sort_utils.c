/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:07 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 20:02:09 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
    First step - Goes through Stack A and only pushes in Stack B the numbers 
    that are under or below the "limit", which is defined in the parsing (i.e 6 
    for 100 numbers and under, or 15 by default). Stops before the last chunk 
    (i.e at 5/6)
*/
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
			sa_or_ss(data);
			tmp = further->next;
			push_b(data);
		}
		else
			tmp = tmp->next;
		i++;
	}
}

/*
    Second step - Sort the last chunk present in Stack A, by pushing to Stack B 
    the smallest numbers until only the 3 biggest numbers are left. Then, 
    applies my 3number-Algorithm.
*/
void    sort_last_chunk(t_data *data)
{
	while (STACK_A)
	{
		isolate_smallest(data);
		push_b(data);
		if (data->len_a == 3)
		{
			apply_algorithm(data->len_a, data);
			push_a(data);
			if (check_sorted(data) == FAILURE)
				swap_a(data);
			break;
		}	
	}
}

/*
    Last step : Pushes everything by to Stack A by dynamically searching for the 
    biggest number and put it on top of Stack B.
*/
void    push_everything_back_to_A(t_data *data)
{
	long int    biggest_nbr;
	t_list *further;

	further = STACK_B->next;
	while (STACK_B)
	{
		biggest_nbr = find_max(STACK_B);
		further = STACK_B->next;
	   
		if (data->len_b >= 2 && biggest_nbr == further->number)
			swap_b(data);
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

int		find_value(t_list *stack, int which_rank)
{
	t_list 		*tmp;
    int         searched_value;
    int         i;
	
	tmp = stack;
    i = 1;

    while (i <= which_rank)
    {
        tmp = tmp->next;
        i++;
    }
    searched_value = tmp->number;
	return (searched_value);
}

int	is_on_top_of(t_list *stack, long int element)
{
    t_list *tmp;

    tmp = stack;
    if (tmp->number == element)
        return (SUCCESS);
    else
        return (FAILURE);
}