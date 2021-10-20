/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:04:58 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/20 18:23:02 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
*/

// void	push_a(t_data *data)
// {
// 	if (data->len_b)
// 	{

// 	}

// }

void	push_b(t_data *data)
{
	long int top_elt_in_a;

	if (data->len_a)
	{
		top_elt_in_a = data->stack_a->number;
		ft_lstadd_front(&data->stack_b, ft_lstnew(top_elt_in_a));

		data->stack_a = data->stack_a->next;

		ft_putstr_fd("pb\n", 1);
		data->len_a = ft_lstsize(data->stack_a);
		data->len_b = ft_lstsize(data->stack_b);
	}

}