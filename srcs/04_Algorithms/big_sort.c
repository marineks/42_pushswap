/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:30:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/25 14:48:33 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
#include <stdio.h>

void    push_chunk_to_B(t_data *data, int limit)
{
    int i;
    t_list *tmp;
    t_list *further;

    tmp = STACK_A;
    i = 1;
    while (i <= data->len_a) 
    {
        further = STACK_A->next;
        if (tmp->number <= limit)
        {
            while (STACK_A->number != tmp->number)
            {  
                if (find_index(tmp, tmp->number) > ft_lstsize(STACK_A)/2)
                    reverse_a(data);
                else
                    rotate_a(data);
            }
            push_b(data);
            tmp = STACK_A; 
        }
        else if (further->number <= limit)
        {
            swap_a(data);
            tmp = further->next;
            push_b(data);
        }
        else
            tmp = tmp->next;
        i++;
    }
}

void	apply_big_num_solver(t_data *data, int nbr)
{
    // t_list *further;

    TOTAL_SIZE = ft_lstsize(COPY);
    // printf("size de la stack: %d\n", TOTAL_SIZE);
    // further = STACK_A->next;
    sort_copy(COPY);

    int count;
    count = 1;
    while (count < nbr)
    {
        CHUNK = find_value(COPY, (TOTAL_SIZE/nbr * count));
        push_chunk_to_B(data, CHUNK);
        count++;
    }
   
    // Trier la stack A en cherchant le smallest number to put on top of stack A
    while (STACK_A)
	{
		isolate_smallest(data);
        push_b(data);
		if (data->len_a == 5)
		{
			apply_algorithm(data->len_a, data);
			push_a(data);
			if (check_sorted(data) == FAILURE)
				swap_a(data);
            break;
			// while (data->len_b > 0)
			// 	push_a(data);
		}	
	}
    // display_stack(data, 'A');
	// display_stack(data, 'B');

    long int    biggest_nbr;

    while (STACK_B)
    {
        biggest_nbr = find_max(STACK_B);
       
        
        while (is_on_top_of(STACK_B, biggest_nbr) == FAILURE)
        {
            if (find_index(STACK_B, biggest_nbr) > ft_lstsize(STACK_B)/2)
                reverse_b(data);
            else
                rotate_b(data);
        }
        push_a(data);
    }

}  



// void    push_biggest_to_A(t_data *data)
// {
//     // t_list *tmp;
//     // t_list *further;

//     while (STACK_B)
//     {
//         if (STACK_B->number == find_max(STACK_B))
//         {
//             while (is_on_top_of(STACK_B, STACK_B->number) == FAILURE)
//             {
//                 if (find_index(STACK_B, STACK_B->number) > find_avg_index(data, STACK_B))
//                     reverse_b(data);
//                 else
//                     rotate_b(data);
//             }
//             push_a(data); 
//         }
//         // else if (further->number <= limit)
//         // {
//         //     swap_a(data);
//         //     tmp = further->next;
//         //     push_b(data);
//         // }
//         else
//         {
//             rotate_b(data);
//         }
//     }
//     // display_stack(data, 'A');
// 	// display_stack(data, 'B');

// }


    // while (STACK_B)
    // {
    //     if (STACK_B->number == find_max(STACK_B))
    //     {
    //         while (is_on_top_of(STACK_B, STACK_B->number) == FAILURE)
    //         {
    //             if (find_index(STACK_B, STACK_B->number) > find_avg_index(data, STACK_B))
    //                 reverse_b(data);
    //             else
    //                 rotate_b(data);
    //         }
    //         push_a(data); 
    //     }
    //     // else if (further->number <= limit)
    //     // {
    //     //     swap_a(data);
    //     //     tmp = further->next;
    //     //     push_b(data);
    // //     // }
    //     else
    //     {
    //         rotate_b(data);
    //     }
    // }
    // display_stack(data, 'A');
	// display_stack(data, 'B');

//  printf("le nombre %ld ", tmp->number);

// if (STACK_A->number <= QUARTER)
//     push_b(data);
// else
//     rotate_a(data);

// tmp = tmp->next;

 // // PUSH TOUS LES NBS EN DESSOUS DE QUARTER DANS B
    // while (contains_els_below(data, QUARTER) == SUCCESS) 
    // {
    //     if (STACK_A && STACK_A->number <= QUARTER)
    //     {
    //         while (is_on_top_of(STACK_A, STACK_A->number) == FAILURE)
    //         {
                
    //             if (find_index(STACK_A, STACK_A->number) > find_avg_index(data, STACK_A))
    //                 reverse_a(data);
    //             else
    //                 rotate_a(data);
    //             // printf("je loop dans is on top\n");
    //         }
    //         push_b(data); 
    //     }
    //     else
    //     {
    //         // printf("le nombre n'est pas dans le chunk\n");
    //         rotate_a(data);
    //         // STACK_A = STACK_A->next;
    //     }
            
    // }
	// // display_stack(data, 'A');
	// // display_stack(data, 'B');

    // // PUSH TOUS LES NBS EN DESSOUS DE MIDDLE DANS B
    // while (contains_els_below(data, MIDDLE) == SUCCESS) 
    // {
    //     if (STACK_A && STACK_A->number <= MIDDLE)
    //     {
    //         while (is_on_top_of(STACK_A, STACK_A->number) == FAILURE)
    //         {
    //             if (find_index(STACK_A, STACK_A->number) > find_avg_index(data, STACK_A))
    //                 reverse_a(data);
    //             else
    //                 rotate_a(data);
    //         }
    //         push_b(data); 
    //     }
    //     else
    //         rotate_a(data);
    // }
	// // display_stack(data, 'A');
	// // display_stack(data, 'B');

    // // PUSH TOUS LES NBS EN DESSOUS DE TROIS QUARTS DANS B
    //  while (contains_els_below(data, THREE_QUARTERS) == SUCCESS) 
    // {
    //     if (STACK_A && STACK_A->number <= THREE_QUARTERS)
    //     {
    //         while (is_on_top_of(STACK_A, STACK_A->number) == FAILURE)
    //         {
    //             if (find_index(STACK_A, STACK_A->number) > find_avg_index(data, STACK_A))
    //                 reverse_a(data);
    //             else
    //                 rotate_a(data);
    //         }
    //         push_b(data); 
    //     }
    //     else
    //         rotate_a(data);
    // }
	// display_stack(data, 'A');
	// display_stack(data, 'B');
