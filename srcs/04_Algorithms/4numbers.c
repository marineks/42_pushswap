/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:42:16 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/22 17:37:48 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int		is_lowest_number(long int compared, long int el2, long int el3, 
		long int el4)
{
	if (compared < el2 && compared < el3 && compared < el4)
		return (SUCCESS);
	else
		return (FAILURE);
}

void	isolate_lowest_el(t_data *data)
{
	t_list *first; 
	t_list *second;
	t_list *third;
	t_list *fourth;

	// On assigne chaque node de la stack de size 3 à sa propre copie
	first = data->stack_a;
	second = first->next;
	third = second->next;
	fourth = third->next;

	if (is_lowest_number(second->number, first->number, third->number,
			fourth->number) == SUCCESS)
				swap_a(data);
	else if (is_lowest_number(third->number, second->number, first->number,
		fourth->number) == SUCCESS 
		|| is_lowest_number(fourth->number, first->number, third->number,
		second->number) == SUCCESS)
	{
		while (is_lowest_number(first->number, fourth->number, third->number,
		second->number) == FAILURE)
		{
			reverse_a(data);
			first = data->stack_a;
			second = first->next;
			third = second->next;
			fourth = third->next;
		}
	}
}

void	apply_4num_solver(t_data *data)
{
	t_list *first; 
	t_list *second;
	t_list *third;
	t_list *fourth;

	// On assigne chaque node de la stack de size 3 à sa propre copie
	first = data->stack_a;
	second = first->next;
	third = second->next;
	fourth = third->next;
	
	// Mon algo qui ne met que 3 coups max
	while (check_sorted(data) == FAILURE)
	{
		isolate_lowest_el(data);
		push_b(data);
		apply_3num_solver(data);
		push_a(data);

		first = data->stack_a;
		second = first->next;
		third = second->next;
		fourth = third->next;
	}
}