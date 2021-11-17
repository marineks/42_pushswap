/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:51:39 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/02 14:57:05 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// void f(void)
// {
// 	system("leaks push_swap");
// }

int main(int argc, char **argv)
{
	t_data data; // data = malloc(sizeof(*t_data));     
	
	if (argc == 1)
		exit(0);
	else
	{            
		initialize(&data, argc);
		put_in_stack_a(argv, &data);
		if (check_duplicates(&data) == FAILURE)
			ft_putstr_fd("Error\n", 2);
		else if (check_sorted(&data) == FAILURE)
		{
			// display_stack(&data, 'A');
			apply_algorithm(argc - 1, &data);
			// display_stack(&data, 'A');
			// display_stack(&data, 'B');
		}
	}
	free_everything(&data);
	// atexit(f);
	return (0);
}