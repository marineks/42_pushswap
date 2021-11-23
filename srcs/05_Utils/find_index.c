/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:12:25 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/23 17:22:02 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>
/*
*/

int find_avg_index(t_data *data)
{
	data->len_a = ft_lstsize(data->stack_a);
	return (data->len_a/2);
}

int find_index(t_list *stack, long int element)
{
	t_list	*tmp;
	int 	i;

	tmp = stack;
	i = 1;
	while (tmp != NULL)
	{
		if (element == tmp->number)
			break;
		tmp = tmp->next;
		i++;
	}
	// printf("i %d:\n", i);
	return (i);
}