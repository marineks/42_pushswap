/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:50:45 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/02 11:49:29 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/checker.h"
#include "../includes/get_next_line.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1)
		exit(0);
	else
	{
		initialize(&data, argc);
		put_in_stack_a(argv, &data);
		if (check_duplicates(&data) == FAILURE)
		{
			ft_putstr_fd("Error\n", 2);
			free_everything(&data);
			exit(0);
		}
		get_instructions(&data);
		if (check_sorted(&data) == SUCCESS && !(data.stack_b))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 2);
	}
	free_everything(&data);
	return (0);
}
