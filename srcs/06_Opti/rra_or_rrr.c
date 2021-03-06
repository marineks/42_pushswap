/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_or_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:43:09 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 12:54:11 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	rra_or_rrr(t_data *data)
{
	t_list	*last;
	t_list	*head;

	if (data->len_b >= 2)
	{
		last = ft_lstlast(data->stack_b);
		head = data->stack_b;
		if (last->number < head->number)
			reverse_both(data);
		else
			reverse_a(data);
	}
	else
		reverse_a(data);
}
