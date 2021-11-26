/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_or_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:41:21 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 11:15:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	ra_or_rr(t_data *data)
{
	t_list	*further;

	if (data->len_b >= 2)
	{
		further = STACK_B->next;
		if (further->number < STACK_B->number)
			rotate_both(data);
		else
			rotate_a(data);
	}
	else
		rotate_a(data);
}
