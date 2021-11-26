/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:29:15 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 10:14:30 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	if (stack)
	{
		while (stack != NULL)
		{
			tmp = stack;
			stack = stack->next;
			free(tmp);
		}
		stack = NULL;
	}
	else
	{
		(void) tmp;
		return ;
	}
}

void	free_everything(t_data *data)
{
	if (data)
	{
		free_stack(STACK_A);
		free_stack(COPY);
		free_stack(STACK_B);
	}
	else
		return ;
}
