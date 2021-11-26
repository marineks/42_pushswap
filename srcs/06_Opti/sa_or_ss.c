/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_or_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:43:40 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 12:54:03 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sa_or_ss(t_data *data)
{
	t_list	*further;

	if (data->len_b >= 2)
	{
		further = data->stack_b->next;
		if (further->number > data->stack_b->number)
			swap_both(data);
		else
			swap_a(data);
	}
	else
		swap_a(data);
}
