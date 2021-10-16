/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:23:44 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/16 15:23:28 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>
/* sa : swap a - swap the first 2 elements at the top of stack a. 
	Do nothing if there is only one or no elements).
	sb : swap b - swap the first 2 elements at the top of stack b. 
	Do nothing if there is only one or no elements).
	ss : sa and sb at the same time. */

void	swap_a(t_data *data)
{
	t_list *tmp;
	long int stocks_first_val;
	long int stocks_second_val;
	if (data->len_a > 1)
	{
		// // Ex: liste de 1 3 2
		stocks_first_val = data->stack_a->number; // stock le 1
		tmp = data->stack_a->next; // tmp pointe vers 3
		stocks_second_val = tmp->number; // stock le 3
		
		data->stack_a = data->stack_a->next; // on avance dans la liste chainee de 1
		data->stack_a->number = stocks_first_val; // 1 2
		ft_lstadd_front(&data->stack_a, ft_lstnew(stocks_second_val)); // 3 1 2

		ft_putstr_fd("sa\n", 1);
	}
}