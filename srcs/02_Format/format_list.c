/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:39:35 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/02 11:23:35 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	initialize(t_data *data, int argc)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->copy_stack_a = NULL;
	data->len_a = argc - 1;
	data->len_b = 0;
	data->print = 1;
}

void	put_in_stack_a(char **arg, t_data *data)
{
	int			i;
	long int	nb;

	i = 1;
	while (arg[i])
	{
		if (is_digit(arg[i]) == SUCCESS
			&& check_quotes(arg[i]) == SUCCESS
			&& check_int_size(arg[i]) == SUCCESS)
		{
			nb = ft_atol(arg[i]);
			ft_lstadd_back(&data->stack_a, ft_lstnew(nb));
			ft_lstadd_back(&data->copy_stack_a, ft_lstnew(nb));
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			free_everything(data);
			exit(0);
		}
		i++;
	}	
}
