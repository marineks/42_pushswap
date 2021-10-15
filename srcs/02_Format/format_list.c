/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:39:35 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/15 17:37:11 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	initialize(t_data *data)
{
	// data->stack_a.number = 0;
	// data->stack_a->next = NULL;
	// data->stack_b.number = 0;
	// data->stack_b->next = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->len_a = 0;
	data->len_b = 0;
	// return (data);
}

void	put_in_stack_a(char **arg, t_data *data)
{
	int 		i;
	long int 	nb;

	i = 1;
	while (arg[i])
	{
		if (is_digit(arg[i]) == SUCCESS && 
			check_int_size(arg[i]) == SUCCESS)
		{
			nb = ft_atol(arg[i]);
			ft_lstadd_back(&data->stack_a, ft_lstnew(nb));
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
	i++;
	}	
}