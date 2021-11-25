/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:59:47 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 14:47:08 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_5num_solver(t_data *data)
{
	while (check_sorted(data) == FAILURE)
	{
		isolate_smallest(data);
		push_b(data);
		apply_4num_solver(data);
		push_a(data);
	}
}