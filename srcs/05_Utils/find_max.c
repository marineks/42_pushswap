/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:06:54 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/18 14:12:43 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
/*
*/

int find_max(t_data *data)
{
	t_list 		*tmp;
	int	max;
	
	tmp = data->stack_a;
	max = data->stack_a->number;
	while (tmp != NULL)
	{
		if (max < tmp->number)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}