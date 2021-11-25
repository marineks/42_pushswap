/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_or_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:43:40 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 19:43:58 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void    sa_or_ss(t_data *data)
{
	t_list *further;

	if (data->len_b >= 2)
	{
		further = STACK_B->next;
		if (further->number > STACK_B->number)
			swap_both(data);
		else
			swap_a(data);
	}
	else
		swap_a(data);
}