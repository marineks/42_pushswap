/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:11:57 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/01 17:00:36 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/checker.h"
#include "../includes/get_next_line.h"
/*

Boucle while(1) pour que le checker attendre que l'on mette des instructions

Mettre un "/n" entre les instructions
Quand toutes les instructions ont ete lu, on execute.

/  peut etre faire :
while (nb_de_coups--)
{
    execute(arg_recu)
}


et execute(char* arg_recu)
{
    GERER LES ERREURS ET METTRE RETOUR SUR 2 (STANDARD ERROR)
    si arg_recu == RA, faire rotate
    etc
    etc
}

et à la fin : 
if (check_sorted(stack_a) == SUCCESS)
    display "OK"
else
    "KO"

*/



void    do_operation(char *str, t_data *data)
{
    int len;
    data->print = 0; 

    len = ft_strlen(str) - 1;
    printf("Str : |%s| | len : %d | result comparaison : %d\n", str, len, ft_strncmp(str, "sa\n", len));
    if (ft_strncmp(str, "ra\n", len) == 0)
        rotate_a(data);
    if (ft_strncmp(str, "rb\n", len) == 0)
        rotate_b(data);
    if (ft_strncmp(str, "rr\n", len) == 0)
        rotate_rr(data);
    if (ft_strncmp(str, "rra\n", len) == 0)
        reverse_a(data);
    if (ft_strncmp(str, "rrb\n", len) == 0)
        reverse_b(data);
    if (ft_strncmp(str, "rrr\n", len) == 0)
        reverse_rrr(data);
    if (ft_strncmp(str, "sa\n", len) == 0)
        swap_a(data);
    if (ft_strncmp(str, "sb\n", len) == 0)
        swap_b(data);
    if (ft_strncmp(str, "ss\n", len) == 0)
        swap_ss(data);
    if (ft_strncmp(str, "pa\n", len) == 0)
        push_a(data);
    if (ft_strncmp(str, "pb\n", len) == 0)
        push_b(data);
    else
    {
        ft_putstr_fd("Error", 2);
        free(str);
        free_everything(data);
        exit(0);
    }
}

void    get_instructions(t_data *data)
{
    // faire une string qui va recueillir l'arg
    char *arg;

    arg = "start";
    // Si on arrive au EOF (aka CTRL+D), arg deviendra NULL et la boucle sera finie;
    while (arg != NULL)
    {
         // get next line en fd 0 pour lire le terminal
        arg = get_next_line(0);

        // executer l'operation
        do_operation(arg, data);
        free(arg);
        

    }
   
    
}


//   if (ft_strlen(str) == 3)                    // Cas RRA / RRB / RRR
//     {
//         if (str[2] == 'a')
//             reverse_a(data);
//         else if (str[2] == 'b')
//             reverse_b(data);
//         else
//             reverse_both(data);
//     }
//     else if (ft_strlen == 2)                    // Cas RA / RB / RR
//     {
//         if (str[0] == 'r')
//         {
//             if (str[1] == 'a')
//                 rotate_a(data);
//             else if (str[1] == 'b')
//                 rotate_b(data);
//             else
//                 rotate_both(data);
//         }
//         else if (str[0] == 's')                 // Cas SA / SB / SS
//         {
//             if (str[1] == 'a')
//                 swap_a(data);
//             else if (str[1] == 'b')
//                 swap_b(data);
//             else
//                 swap_both(data);
//         }
//         else if (str[0] == 'p')                 // Cas PA / PB
//         {
//             if (str[1] == 'a')
//                 push_a(data);
//             else if (str[1] == 'b')
//                 push_b(data);
//         }
        
//     }