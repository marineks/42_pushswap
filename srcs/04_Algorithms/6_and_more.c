/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_and_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:26:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/02 14:53:28 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>
/*
	Idéalement, j'aimerais profiter de cet exercice pour connaitre les plus
	grands théorèmes d'algo de tri.
	Pour le moment, j'ai jeté mon dévolu sur le Tri Fusion (Merge Sort) 
	car c'est celui qui a la complexité temporelle la plus optimale. 
	De plus il utilise la récursivité.
	Principe du tri fusion: séparer la stack A en deux parts égales;
	trier récursivement les deux parties et fusionner les deux stacks.
*/

int find_lowest(t_data *data)
{
	t_list 		*tmp;
	int	lowest;
	
	tmp = data->stack_a;
	lowest = data->stack_a->number;
	// printf("Lowest de début: %d\n", lowest);
	while (tmp != NULL)
	{
		if (lowest > tmp->number)
			lowest = tmp->number;
		tmp = tmp->next;
	}
	// printf("Lowest de fin: %d\n", lowest);
	return (lowest);
}

int find_avg_index(t_data *data)
{
	data->len_a = ft_lstsize(data->stack_a);
	return (data->len_a/2);
}

int find_index(t_data *data, long int element)
{
	t_list	*tmp;
	int 	i;

	tmp = data->stack_a;
	i = 1;
	while (tmp != NULL)
	{
		if (element == tmp->number)
			break;
		tmp = tmp->next;
		i++;
	}
	// printf("i %d:\n", i);
	return (i);
}

void apply_big_num_solver(t_data *data)
{
	t_list *tmp;
	long int first_el;

	tmp = data->stack_a;
	first_el = tmp->number;
	while (check_sorted(data) == FAILURE)
	{
		if (find_index(data, find_lowest(data)) > find_avg_index(data))
		{
			while (is_lowest(data, first_el) == FAILURE)
			{
				reverse_a(data);
				tmp = data->stack_a;
				first_el = tmp->number;
			}
			push_b(data);
		} 
		else
		{
			while (is_lowest(data, first_el) == FAILURE)
			{
				rotate_a(data);
				tmp = data->stack_a;
				first_el = tmp->number;
			}
			push_b(data);
		}
		if (data->len_a == 5)
		{
			apply_algorithm(data->len_a, data);
			push_a(data);
			if (check_sorted(data) == FAILURE)
				swap_a(data);
			while (data->len_b > 0)
				push_a(data);
		}	
		tmp = data->stack_a;
		first_el = tmp->number;
	}
}

