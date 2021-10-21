/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:45:05 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/21 14:50:31 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/* 
	Par principe, vu que l'on teste en amont si la string est déjà ordonnée
	Cela veut dire que la stack se présente actuellement sous cette forme:
	< ./pushswap PLUS_GRAND_NOMBRE PETIT_NOMBRE >
	Il suffit donc de rotate la stack pour inverser les deux nombres.
*/
void	apply_2num_solver(t_data *data)
{
	rotate_a(data);
}