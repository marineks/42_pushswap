/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:46:15 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 09:24:29 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	check_duplicates(t_data *data)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = data->stack_a;
	tmp2 = tmp;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp2 = tmp2->next;
		while (tmp2 != NULL)
		{
			if (tmp->number == tmp2->number)
				return (FAILURE);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}
