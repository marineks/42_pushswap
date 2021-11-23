/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:29:15 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/23 16:27:04 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	free_everything(t_data *data)
{
	t_list *tmp;
	t_list *tmp_b;
	t_list *tmp_copy;

	if (data)
	{
		if (data->stack_a)
		{
			while (data->stack_a != NULL)
			{
				tmp = data->stack_a;
				data->stack_a = data->stack_a->next;
				free(tmp);
			}
			data->stack_a = NULL;
		}
		if (data->copy_stack_a)
		{
			while (data->copy_stack_a != NULL)
			{
				tmp_copy = data->copy_stack_a;
				data->copy_stack_a = data->copy_stack_a->next;
				free(tmp_copy);
			}
			data->copy_stack_a = NULL;
		}
		if (data->stack_b)
		{
			while (data->stack_b != NULL)
			{
				tmp_b = data->stack_b;
				data->stack_b = data->stack_b->next;
				free(tmp_b);
			}
		}
		// free(data);
	}
	else
		return ;
}