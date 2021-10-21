/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:51:39 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/21 14:55:12 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void f(void)
{
	system("leaks push_swap");
}

int main(int argc, char **argv)
{
	t_data data; // data = malloc(sizeof(*t_data));     
	
	if (!(argc > 2))
		ft_putstr_fd("Error wrong number of arguments\n", 2);
	else
	{            
		initialize(&data, argc);
		put_in_stack_a(argv, &data);
		if (check_duplicates(&data) == FAILURE)
		{
			ft_putstr_fd("Error : there is at least one duplicate\n", 2);
			exit(0);
		} 
		else if (check_sorted(&data) == SUCCESS)
		{
			ft_putstr_fd("The list is already sorted.\n", 2);
			exit(0);
		}
		else
		{
			display_stack(&data, 'A');
			apply_algorithm(argc - 1, &data);
		}
	}
	free_everything(&data);
	atexit(f);
	return (0);
}