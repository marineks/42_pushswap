/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:50:45 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/02 11:06:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/checker.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

/*

Le checker doit prendre en argument la série de nombres à trier donc reprendre 
son format list et le mettre dans une liste chainée

Le 1er arg doit etre en haut de la liste (normalement cest deja le cas avec mon 
code)

Si pas d'arg le checker s'arrete

*/

int	main(int argc, char **argv)
{
	t_data	data;

    /* If no argument is given, checker stops and displays nothing. */
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