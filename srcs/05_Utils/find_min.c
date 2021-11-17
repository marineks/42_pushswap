/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:09:04 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/17 18:11:31 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>
/*
*/

int find_lowest(t_data *data)
{
	t_list 		*tmp;
	int	lowest;
	
	tmp = data->stack_a;
	lowest = data->stack_a->number;
	while (tmp != NULL)
	{
		if (lowest > tmp->number)
			lowest = tmp->number;
		tmp = tmp->next;
	}
	return (lowest);
}