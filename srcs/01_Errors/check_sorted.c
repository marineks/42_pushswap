/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:46:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/16 12:16:45 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	check_sorted(t_data *data)
{
	t_list *copy_of_list;
	t_list *one_step_further;

	copy_of_list = data->stack_a;
	one_step_further = copy_of_list->next;
	while (one_step_further != NULL)
	{
		// printf("Num de tmp : %ld | Num de tmp2: %ld\n", tmp->number, tmp2->number);
		if (copy_of_list->number > one_step_further->number)
		{
			ft_putstr_fd("The list is already sorted.\n", 2);
			free(data);
			return (FAILURE);
		}
		copy_of_list = copy_of_list->next;
		one_step_further = copy_of_list->next;
	}
	return (SUCCESS);
}