/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:46:17 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/15 16:28:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

long int	ft_atol(const char *str)
{
	long int	result;
	int			n;
	long int	i;

	result = 0;
	n = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * n);
}

int check_int_size(char *str)
{
	long int number;

	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		return (FAILURE);
	else
		return (SUCCESS);	
}

// int main()
// {
// 		char *str = "012";
// 		char *str1 = "-2147483648";	
// 		char *str2 = "2147483647";	
// 		char *str3 = "2147493649";	
// 		char *str4 = "-2257483648";	

// 		check_int_size(str);  // expected OK
// 		check_int_size(str1); // INT MIN
// 		check_int_size(str2); // INT MAX
// 		check_int_size(str3); // expected KO
// 		check_int_size(str4); // expected KO
// 	return (0);
// }