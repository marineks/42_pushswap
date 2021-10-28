/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_and_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:26:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/28 17:49:03 by msanjuan         ###   ########.fr       */
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

long int find_lowest(t_data *data)
{
	t_list 		*tmp;
	long int	lowest;
	
	tmp = data->stack_a;
	lowest = tmp->number;
	printf("Lowest de début: %lu\n", lowest);
	while (tmp != NULL)
	{
		if (tmp->number < lowest)
			lowest = tmp->number;
		tmp = tmp->next;
	}
	printf("Lowest de fin: %lu\n", lowest);
	return (lowest);
}

int find_avg_index(t_data *data)
{
	return (data->len_a/2);
}

void apply_big_num_solver(t_data *data)
{
	printf("Find avg indx : %i\n", find_avg_index(data));
	find_lowest(data);
}