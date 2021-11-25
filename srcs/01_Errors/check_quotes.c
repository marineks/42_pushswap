/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:05:05 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 17:11:46 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int check_quotes(char *arg)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (arg[i])
    {
        if (arg[i] == '\"')
            count++;
        i++;
    }
    if (count == 2)
        return (FAILURE);
    else
        return (SUCCESS);
}