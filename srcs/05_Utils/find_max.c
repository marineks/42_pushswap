/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:06:54 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/02 11:36:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	find_max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = stack->number;
	while (tmp != NULL)
	{
		if (max < tmp->number)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

int	find_second_to_max(t_list *stack)
{
	t_list	*tmp;
	int		max;
	int		second_max;

	max = find_max(stack);
	tmp = stack;
	second_max = stack->number;
	while (tmp != NULL)
	{
		if (second_max < tmp->number && tmp->number != max)
			second_max = tmp->number;
		tmp = tmp->next;
	}
	return (second_max);
}
