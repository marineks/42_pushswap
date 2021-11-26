/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:34:47 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 15:51:22 by msanjuan         ###   ########.fr       */
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

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*copy_stack_a;
	int		len_a;
	int		len_b;
	int		total_size;
	int		chunk;
	int		print;
}				t_data;

//      01 - CHECK ERRORS
long int	ft_atol(const char *str);
int			is_digit(char *arg);
int			check_quotes(char *arg);
int			check_int_size(char *str);
int			check_duplicates(t_data *data);
int			check_sorted(t_data *data);

//      02 - FORMAT
void		initialize(t_data *data, int argc);
void		put_in_stack_a(char **argv, t_data *data);
void		display_stack(t_data *data, char which_stack);
void		free_everything(t_data *data);

//      03 - OPERATIONS
void		swap_a(t_data *data);
void		swap_b(t_data *data);
void		swap_both(t_data *data);
void		rotate_a(t_data *data);
void		rotate_b(t_data *data);
void		rotate_both(t_data *data);
void		reverse_a(t_data *data);
void		reverse_b(t_data *data);
void		reverse_both(t_data *data);
void		push_a(t_data *data);
void		push_b(t_data *data);

//		04 - ALGORITHMS
void		apply_algorithm(int size_of_stack_a, t_data *data);
void		apply_2num_solver(t_data *data);
void		apply_3num_solver(t_data *data);
void		apply_4num_solver(t_data *data);
void		apply_5num_solver(t_data *data);
void		apply_insert_solver(t_data *data);
void		apply_big_num_solver(t_data *data, int nbr);

//		05 - UTILS
int			is_lowest(t_data *data, long int compared);
int			find_lowest(t_list *stack);
int			find_max(t_list *stack);
int			find_index(t_list *stack, long int element);
int			find_value(t_list *stack, int which_rank);
int			find_second_to_max(t_list *stack);
int			is_on_top_of(t_list *stack, long int element);
void		isolate_smallest(t_data *data);
void		sort_copy(t_list *stack);
void		sort_last_chunk(t_data *data);
void		push_chunk_to_b(t_data *data, int limit);
void		push_everything_back_to_a(t_data *data);

//		06 - OPTI
void		rra_or_ra(t_data *data, t_list *tmp);
void		sa_or_ss(t_data *data);
void		ra_or_rr(t_data *data);
void		rra_or_rrr(t_data *data);

#endif
