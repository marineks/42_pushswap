/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:04:25 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/01 16:32:10 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// CHECKER.c
void    get_instructions(t_data *data);
void    do_operation(char *str, t_data *data);

// DOUBLE_OP_EXCEPTION.c
void	reverse_rrr(t_data *data);
void	rotate_rr(t_data *data);
void	swap_ss(t_data *data);

#endif
