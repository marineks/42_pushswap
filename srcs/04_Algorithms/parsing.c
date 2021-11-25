/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:24:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 19:03:13 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	apply_algorithm(int size_of_stack_a, t_data *data)
{
	if (size_of_stack_a == 2)
		apply_2num_solver(data);
	else if (size_of_stack_a == 3)
		apply_3num_solver(data);
	else if (size_of_stack_a == 4)
		apply_4num_solver(data);
	else if (size_of_stack_a == 5)
		apply_5num_solver(data);
	else if (size_of_stack_a <= 20)
		apply_insert_solver(data);
	else if (size_of_stack_a <= 100)
		apply_big_num_solver(data, 6);
	else
		apply_big_num_solver(data, 15);
}
