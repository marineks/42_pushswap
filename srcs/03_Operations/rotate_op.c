/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:35:37 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/22 17:07:36 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

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
		// Exemple 3 -> 1 -> 2
		head = data->stack_a; // 3
		last = ft_lstlast(data->stack_a); // 2

		// on coupe le premier node, sauvegardé dans HEAD. => 3 1 2 devient 1 2
		data->stack_a = data->stack_a->next;
		// On attache le 3 à la fin du 2 donc 1 2 3 1 2
		last->next = head;
		// On met bien NULL à la fin de HEAD (3). Donc 1 2 3
		head->next = NULL;
		
		ft_putstr_fd("ra\n", 1);
		// display_stack(data, 'A');
	}
}

void	rotate_b(t_data *data)
{
	t_list *head;
	t_list *last;

	if (data->len_b > 1)
	{
		// Exemple 3 -> 1 -> 2
		head = data->stack_b; // 3
		last = ft_lstlast(data->stack_b); // 2

		// on coupe le premier node, sauvegardé dans HEAD. => 3 1 2 devient 1 2
		data->stack_b = data->stack_b->next;
		// On attache le 3 à la fin du 2 donc 1 2 3 1 2
		last->next = head;
		// On met bien NULL à la fin de HEAD (3). Donc 1 2 3
		head->next = NULL;
		
		ft_putstr_fd("rb\n", 1);
		// display_stack(data, 'B');
	}
}

void	rotate_both(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
	ft_putstr_fd("rr\n", 2);
	// display_stack(data, 'A');
	// display_stack(data, 'B');
}
