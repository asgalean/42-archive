/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:08:16 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:39:51 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_node *stack)
{
	int		number;
	t_node	*temp;

	number = stack->number;
	temp = stack;
	while (temp->next->number != stack->number)
	{
		if (temp->next->number < number)
			number = temp->next->number;
		temp = temp->next;
	}
	while (number != stack->number)
		stack = stack->next;
	return (stack->pos);
}

//*****************************************************************************
//*****************************************************************************

int	find_insertion_position(t_node *stack_a, int num_to_insert)
{
	t_node	*current;
	int		len;
	int		i;

	current = stack_a;
	len = list_len(stack_a);
	i = 0;
	while (i < len)
	{
		if ((current->number < num_to_insert
				&& num_to_insert < current->next->number)
			|| (current->number > current->next->number
				&& num_to_insert < current->next->number)
			|| (current->number > current->next->number
				&& num_to_insert > current->number))
		{
			return (current->next->pos);
		}
		current = current->next;
		i++;
	}
	return (0);
}

//*****************************************************************************
//*****************************************************************************

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->prev->number;
	if (a > b && b > c)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack);
	else if (a > b && b < c && a < c)
		swap_a(stack);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack);
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
}

//*****************************************************************************
//*****************************************************************************

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	while ((*stack_a)->pos
		!= find_insertion_position(*stack_a, (*stack_b)->number))
	{
		if (find_insertion_position(*stack_a, (*stack_b)->number)
			> list_len(*stack_a) / 2)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_a(stack_b, stack_a);
	while ((*stack_a)->pos != find_min_position(*stack_a))
	{
		if (find_min_position(*stack_a) > list_len(*stack_a) / 2)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}
