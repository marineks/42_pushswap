/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:59:47 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/02 17:38:45 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

// MOINS DE 12 COUPS - Mon algo ne met entre 5 et 10 coups max 
/*
		9 pour  3 5 1 4 2 // 10 pour 4 2 1 3 5 // 11 pour 2 5 1 4 3
	Piste pour optimiser : le pb c'est quand le 1 est au milieu, ca coute 3 RRA
	de l'isoler => il vaut mieux 2 RA ?
*/
void	apply_5num_solver(t_data *data)
{
	while (check_sorted(data) == FAILURE)
	{
		isolate_lowest_el(data);
		push_b(data);
		apply_4num_solver(data);
		push_a(data);
	}
}