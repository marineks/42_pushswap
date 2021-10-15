/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:39:35 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/15 16:00:25 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	initialize(t_data data)
{
	data.stack_a->number = NULL;
	data.stack_a->next = NULL;
	data.stack_b->number = NULL;
	data.stack_b->next = NULL;
	data.len_a = 0;
	data.len_b = 0;
	// return (data);
}

t_list	put_in_stack_a(char **argv)
{
	int i;
	int j;
	int *stack_a;

	stack_a = malloc(sizeof(int) * (argc - 1));
	i = 1;
	j = 0;
	while (arg[i])
	{
		if (is_digit(arg[i]) == SUCCESS && 
			is_int_compliant(arg[i]) == SUCCESS)
		{
			stack_a[j] = ft_atoi(arg[i]);
			j++;
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
	i++;
	}
	return (stack_a);	
}