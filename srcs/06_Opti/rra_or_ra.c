/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_or_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:42:13 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 11:17:47 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	rra_or_ra(t_data *data, t_list *tmp)
{
	while (STACK_A->number != tmp->number)
	{
		if (find_index(tmp, tmp->number) > ft_lstsize(STACK_A) / 2)
		{
			rra_or_rrr(data);
		}
		else
			ra_or_rr(data);
	}
}
