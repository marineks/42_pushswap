/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:42:16 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/23 20:52:58 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

// Mon algo qui ne met que 5 coups max
void	apply_4num_solver(t_data *data)
{
	while (check_sorted(data) == FAILURE)
	{
		isolate_smallest(data);
		push_b(data);
		apply_3num_solver(data);
		push_a(data);
	}
}