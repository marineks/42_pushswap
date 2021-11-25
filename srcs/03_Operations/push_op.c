/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:04:58 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 14:47:25 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
*/

void	push_a(t_data *data)
{
	t_list		*copy;
	
	if (data->len_b > 0)
	{
		copy = data->stack_b;
		data->stack_b = data->stack_b->next;
		copy->next = NULL;
		ft_lstadd_front(&data->stack_a, copy);

		ft_putstr_fd("pa\n", 1);
		data->len_a = ft_lstsize(data->stack_a);
		data->len_b = ft_lstsize(data->stack_b);
	}
}

void	push_b(t_data *data)
{
	t_list		*copy;

	if (data->len_a > 0)
	{
		copy = data->stack_a;
		data->stack_a = data->stack_a->next;
		
		copy->next = NULL;
		ft_lstadd_front(&data->stack_b, copy);

		ft_putstr_fd("pb\n", 1);
		data->len_a = ft_lstsize(data->stack_a);
		data->len_b = ft_lstsize(data->stack_b);
	}
}