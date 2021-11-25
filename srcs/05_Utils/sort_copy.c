/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:08:21 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 14:40:53 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

void    sort_copy(t_list *stack)
{
    t_list      *one_step_further;
    t_list      *head;
	int	temp;

    head = stack;
    one_step_further = head->next;
    while (head != NULL)
    {
        one_step_further = head->next;
    
        while (one_step_further != NULL)
        {
            if (head->number > one_step_further->number)
            {
                temp = head->number;
                head->number = one_step_further->number;
                one_step_further->number = temp;
            }
            one_step_further = one_step_further->next;
        } 
        head = head->next;
    }
}
