/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:23:44 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/21 15:32:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
/* sa : swap a - swap the first 2 elements at the top of stack a. 
	Do nothing if there is only one or no elements).
	sb : swap b - swap the first 2 elements at the top of stack b. 
	Do nothing if there is only one or no elements).
	ss : sa and sb at the same time. */

void	swap_a(t_data *data)
{
	t_list *head;
	t_list *remaining_nodes;
	
	if (data->len_a > 1)
	{
		// EXEMPLE: Stack A => < 2 1 3 > devient < 1 2 3 >
		head = data->stack_a; // head pointe vers le 2 (1 3)
		data->stack_a = data->stack_a->next; // Stack A pointe vers le 1 (3)
		remaining_nodes = data->stack_a->next; // on stock le pointeur vers le 3
		data->stack_a->next = head; // le 1 pointe mnt vers le 2  soit [1] 2 (1 3)
		head->next = remaining_nodes; // on raccroche le 2 au 3;

		ft_putstr_fd("sa\n", 1);
		display_stack(data, 'A');
	}
}

void	swap_b(t_data *data)
{
	t_list *head;
	t_list *remaining_nodes;

	if (data->len_b > 1)
	{
		head = data->stack_b;
		data->stack_b = data->stack_b->next;
		remaining_nodes = data->stack_b->next;
		data->stack_b->next = head;
		head->next = remaining_nodes;
		ft_putstr_fd("sb\n", 1);
		display_stack(data, 'B');
	}
}

void swap_both(t_data *data)
{
	swap_a(data);
	swap_b(data);
	ft_putstr_fd("ss\n", 1);
	display_stack(data, 'A');
	display_stack(data, 'B');
}