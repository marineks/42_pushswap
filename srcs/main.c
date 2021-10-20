/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:51:39 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/20 17:18:07 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void f(void)
{
	system("leaks push_swap");
}

int main(int argc, char **argv)
{
	t_data data;
	
	if (!(argc > 3))
		ft_putstr_fd("Error wrong number of arguments\n", 2);
	else
	{
		// data = malloc(sizeof(*t_data));                     
		initialize(&data);
		data.len_a = argc - 1;
		put_in_stack_a(argv, &data);
		if (check_duplicates(&data) == FAILURE)
		{
			ft_putstr_fd("Error : there is at least one duplicate\n", 2);
			// free(data);
			exit(0);
		} 
		else if (check_sorted(&data) == SUCCESS)
		{
			ft_putstr_fd("The list is already sorted.\n", 2);
			// free(data);
			exit(0);
		}
		else
		{
			display_stack(&data, 'A');
			// swap_a(&data);
			// rotate_a(&data);
			reverse_a(&data);
			display_stack(&data, 'A');

			// free(data);
		}
	}
	free_everything(&data);
	atexit(f);
	return (0);
}