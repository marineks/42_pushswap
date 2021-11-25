/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:35:37 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 18:24:11 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/* 
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one. ex:  3 1 2 devient 1 2 3 
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time
*/

void	rotate_a(t_data *data)
{
	t_list *head;
	t_list *last;

	if (data->len_a > 1)
	{
		head = data->stack_a;
		last = ft_lstlast(data->stack_a);

		data->stack_a = data->stack_a->next;
		last->next = head;
		head->next = NULL;

		if (data->print == 1)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_b(t_data *data)
{
	t_list *head;
	t_list *last;

	if (data->len_b > 1)
	{

		head = data->stack_b;
		last = ft_lstlast(data->stack_b);

		data->stack_b = data->stack_b->next;
		last->next = head;
		head->next = NULL;
		
		if (data->print == 1)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_both(t_data *data)
{
	data->print = 0;
	rotate_a(data);
	rotate_b(data);
	ft_putstr_fd("rr\n", 1);
	data->print = 1;
}
