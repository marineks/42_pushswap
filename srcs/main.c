/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:51:39 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 11:29:26 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		exit(0);
	else
	{
		initialize(&data, argc);
		put_in_stack_a(argv, &data);
		if (check_duplicates(&data) == FAILURE)
			ft_putstr_fd("Error\n", 2);
		else if (check_sorted(&data) == FAILURE)
			apply_algorithm(argc - 1, &data);
	}
	free_everything(&data);
	return (0);
}
