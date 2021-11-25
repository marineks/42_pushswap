/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:12:25 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 20:06:06 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

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
	return (i);
}
