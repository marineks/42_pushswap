/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:40:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/24 13:43:39 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int		is_lowest(t_data *data, long int compared)
{
	t_list *tmp;

	tmp = data->stack_a;

	while (tmp != NULL)
	{
		if (compared > tmp->number) // on s'en moque s'il croise son dupe car ce sera == et non >
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}