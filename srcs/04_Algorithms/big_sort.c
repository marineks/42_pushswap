/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 12:49:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_big_num_solver(t_data *data, int nbr)
{
	int	count;
	int	index;

	count = 1;
	data->total_size = ft_lstsize(data->copy_stack_a);
	sort_copy(data->copy_stack_a);
	while (count < nbr)
	{
		index = data->total_size / nbr * count;
		data->chunk = find_value(data->copy_stack_a, index);
		push_chunk_to_b(data, data->chunk);
		count++;
	}
	sort_last_chunk(data);
	push_everything_back_to_a(data);
}
