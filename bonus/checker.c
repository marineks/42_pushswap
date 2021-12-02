/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:11:57 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/02 11:58:28 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/checker.h"
#include "../includes/get_next_line.h"

void	exit_error(t_data *data, char *str)
{
	ft_putstr_fd("Error", 2);
	free(str);
	free_everything(data);
	exit(0);
}

void	do_operation(char *str, t_data *data)
{
	data->print = 0;
	if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate_a(data);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate_b(data);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rotate_rr(data);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		reverse_a(data);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		reverse_b(data);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		reverse_rrr(data);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		swap_a(data);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap_b(data);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		swap_ss(data);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push_a(data);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push_b(data);
	else
		exit_error(data, str);
}

void	get_instructions(t_data *data)
{
	char	*arg;

	arg = get_next_line(0);
	while (arg != NULL)
	{
		do_operation(arg, data);
		free(arg);
		arg = get_next_line(0);
	}
	free(arg);
}
