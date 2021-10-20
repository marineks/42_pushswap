/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:37:15 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/20 17:53:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>
/* 
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.
*/

t_list *ft_before_last(t_list *stack, int len)
{
	int i = 1;
	while(i < len - 1)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

void	reverse_a(t_data *data)
{

	t_list *before_last;
	t_list *last;
	data->len_a = ft_lstsize(data->stack_a);
	if (data->len_a > 1)
	{
		// EXEMPLE Une stack A <2 3 1> devient <1 2 3>
		before_last = ft_before_last(data->stack_a, data->len_a); // Pointe sur 3 => 3 (1)
		last = ft_lstlast(data->stack_a); // Pointe sur 1 (dernier node)

		last->next = data->stack_a; // Le node du "1" pointe vers le "2" => 1 2 (3 1) // boucle sans fin
		before_last->next = NULL; // On coupe le 1 de fin => [1 2] 3 X
		data->stack_a = last; //  on raccroche le "1" à la stack A qui fait 2 3 X
		
		ft_putstr_fd("rra\n", 1);
	}
}


void	reverse_b(t_data *data)
{

	t_list *before_last;
	t_list *last;

	data->len_b = ft_lstsize(data->stack_b);
	if (data->len_b > 1)
	{
		before_last = ft_before_last(data->stack_b, data->len_b);
		last = ft_lstlast(data->stack_b);

		last->next = data->stack_b;
		before_last->next = NULL; 
		data->stack_b = last; 
		
		ft_putstr_fd("rrb\n", 1);
	}
}

void reverse_both(t_data *data)
{
	reverse_a(data);
	reverse_b(data);
	ft_putstr_fd("rrr\n", 1);
}