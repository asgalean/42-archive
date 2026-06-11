/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:08:10 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:39:51 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	babburu_sorto(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

//*****************************************************************************
//*****************************************************************************

void	radix_index_get(t_node *stack)
{
	int			*sorted_array;
	static int	i = -1;
	int			j;
	int			len_list;

	len_list = list_len(stack);
	sorted_array = (int *)malloc(sizeof(int) * len_list);
	while (++i < len_list)
	{
		sorted_array[i] = stack->number;
		stack = stack->next;
	}
	babburu_sorto(sorted_array, len_list);
	i = -1;
	while (++i < len_list)
	{
		j = -1;
		while (++j < len_list)
		{
			if (sorted_array[i] == stack->number)
				stack->radix_index = i;
			stack = stack->next;
		}
	}
	free(sorted_array);
}

//*****************************************************************************
//*****************************************************************************

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	size = list_len(*stack_a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->radix_index >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_a(stack_b, stack_a);
	}
}
