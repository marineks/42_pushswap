/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:08:11 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 20:07:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

void	display_stack(t_data *data, char which_stack)
{
	int i;
	t_list *tmp;
	// t_list *tmp_b;

	i = 0;
	tmp = data->stack_a;
	// tmp_b = data->stack_b;
	printf("  |====== STACK %c ======|  \n", which_stack);
	printf("  |                     |  \n");
	if (which_stack == 'B')
		tmp = data->stack_b;
	while (tmp != NULL)
	{
		printf("       i: %d  No: %ld    \n", i, tmp->number);
		i++;
		tmp = tmp->next;
	}
	printf("  |                     |   \n");
	printf("  |=====================|   \n");
	printf("\n\n");
}
