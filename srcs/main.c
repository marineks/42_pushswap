/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:51:39 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/15 19:09:42 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int main(int argc, char **argv)
{
	t_data *data;
	
	if (!(argc > 3))
		ft_putstr_fd("Error arg\n", 2);
	else
	{
		data = malloc(sizeof(t_data));                     
		data->len_a = argc - 1;
		initialize(data);
		put_in_stack_a(argv, data);
		if (check_duplicates(data) == FAILURE)
			exit(0);
		// if (check_sorted(data) == SUCCESS)
		// 	{
		// 		ft_putstr_fd("Already Sorted\n", 2);
		// 		free(data);
		// 		exit(0);
		// 	}
		else
		{
			ft_putstr_fd("hihi\n", 1);
			display_stack(data, 'A');
		// si ce n'est pas le cas, trier : 
		// mettre dans la fonction ft_sort une ellipse? 

		}
		free(data);
	}
	return (0);
}