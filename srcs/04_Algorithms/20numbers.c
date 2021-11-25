/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:11:22 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 14:48:05 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pushswap.h"

void    apply_insert_solver(t_data *data)
{
    while (check_sorted(data) == FAILURE)
	{
		isolate_smallest(data);
        push_b(data);
		if (data->len_a == 5)
		{
			apply_algorithm(data->len_a, data);
			push_a(data);
			if (check_sorted(data) == FAILURE)
				swap_a(data);
			while (data->len_b > 0)
				push_a(data);
		}	
	}
}
