/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_or_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:43:09 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 19:43:29 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void    rra_or_rrr(t_data *data)
{
	t_list *last;
	t_list *head;

	if (data->len_b >= 2)
	{
		last = ft_lstlast(STACK_B);
		head = STACK_B;
		if (last->number < head->number)
			reverse_both(data);
		else
			reverse_a(data);
	}
	else
		reverse_a(data);
}
