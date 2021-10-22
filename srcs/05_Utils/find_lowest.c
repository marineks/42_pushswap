/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:40:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/22 17:46:53 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int		is_lowest(long int compared, long int el2, long int el3, long int el4)
{
	if (compared < el2 && compared < el3 && compared < el4)
		return (SUCCESS);
	else
		return (FAILURE);
}
