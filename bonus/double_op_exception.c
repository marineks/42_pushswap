/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_op_exception.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:17:03 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/02 12:00:17 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/checker.h"
#include "../includes/get_next_line.h"

void	reverse_rrr(t_data *data)
{
	reverse_a(data);
	reverse_b(data);
}

void	rotate_rr(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}

void	swap_ss(t_data *data)
{
	swap_a(data);
	swap_b(data);
}
