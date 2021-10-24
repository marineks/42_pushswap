/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:34:47 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/24 13:53:29 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define SUCCESS 0
# define FAILURE -1

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_data
{
	t_list *stack_a;
	t_list *stack_b;
	int len_a;
	int len_b;
}				t_data;

//      01 - CHECK ERRORS
int			is_digit(char *arg);
long int	ft_atol(const char *str);
int 		check_int_size(char *str);
int			check_duplicates(t_data *data);
int			check_sorted(t_data *data);

//      02 - FORMAT
void	initialize(t_data *data, int argc);
void	put_in_stack_a(char **argv, t_data *data);
void	display_stack(t_data *data, char which_stack);
void	free_everything(t_data *data);

//      03 - OPERATIONS
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void 	swap_both(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_both(t_data *data);
void	reverse_a(t_data *data);
void	reverse_b(t_data *data);
void	reverse_both(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);

//		04 - ALGORITHMS
void	apply_algorithm(int size_of_stack_a, t_data *data);
void	apply_2num_solver(t_data *data);
void	apply_3num_solver(t_data *data);
void	apply_4num_solver(t_data *data);
void	apply_5num_solver(t_data *data);

//		05 - UTILS
// int		is_lowest(long int compared, long int el2, long int el3, long int el4);
void	isolate_lowest_el(t_data *data);
int		is_lowest(t_data *data, long int compared);
#endif
