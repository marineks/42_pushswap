/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:46:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/16 14:04:49 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	check_sorted(t_data *data)
{
	t_list *copy;
	t_list *one_step_further;

	copy = data->stack_a;
	one_step_further = copy->next;
	while (one_step_further != NULL)
	{
		// printf("Num de tmp : %ld | Num de tmp2: %ld\n", tmp->number, tmp2->number);
		if (copy->number > one_step_further->number)
			return (FAILURE);
		copy = copy->next;
		one_step_further = copy->next;
	}
	return (SUCCESS);
}