/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:46:15 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/15 18:26:56 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

int	check_duplicates(t_data *data)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = tmp2 = data->stack_a;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp2 = tmp2->next;
		while (tmp2 != NULL)
		{
			printf("Num de tmp : %ld | Num de tmp2: %ld\n", tmp->number, tmp2->number);
			if(tmp->number == tmp2->number)
			{
				ft_putstr_fd("Error dup\n", 2);
				free(data);
				return (FAILURE);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

// int check_duplicates(int numbers[], int len)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < len)
// 	{
// 		while (j < i)
// 		{
// 			if (numbers[i] == numbers[j])
// 				return (FAILURE);
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	return (SUCCESS);
// }