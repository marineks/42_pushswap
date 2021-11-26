/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 11:49:43 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_big_num_solver(t_data *data, int nbr)
{
	int	count;

	count = 1;
	TOTAL_SIZE = ft_lstsize(COPY);
	sort_copy(COPY);
	while (count < nbr)
	{
		CHUNK = find_value(COPY, (TOTAL_SIZE / nbr * count));
		push_chunk_to_b(data, CHUNK);
		count++;
	}
	sort_last_chunk(data);
	push_everything_back_to_a(data);
}
