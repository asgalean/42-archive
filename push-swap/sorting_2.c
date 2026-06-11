/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:26:39 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:39:51 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_until_pushable(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->pos
		!= find_insertion_position(*stack_a, (*stack_b)->number))
	{
		if (find_insertion_position(*stack_a, (*stack_b)->number)
			> list_len(*stack_a) / 2)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}
//*****************************************************************************
//*****************************************************************************

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	rotate_a_until_pushable(stack_a, stack_b);
	push_a(stack_b, stack_a);
	rotate_a_until_pushable(stack_a, stack_b);
	push_a(stack_b, stack_a);
	while ((*stack_a)->pos != find_min_position(*stack_a))
	{
		if (find_min_position(*stack_a) > list_len(*stack_a) / 2)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}
