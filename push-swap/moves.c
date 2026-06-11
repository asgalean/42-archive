/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:07:54 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:39:51 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack_head)
{
	int	temp;
	int	radix_temp;

	temp = (*stack_head)->number;
	radix_temp = (*stack_head)->radix_index;
	(*stack_head)->number = (*stack_head)->next->number;
	(*stack_head)->radix_index = (*stack_head)->next->radix_index;
	(*stack_head) = (*stack_head)->next;
	(*stack_head)->number = temp;
	(*stack_head)->radix_index = radix_temp;
	(*stack_head) = (*stack_head)->prev;
}

//*****************************************************************************
//*****************************************************************************

void	reverse_rotate(t_node **stack_head)
{
	int	i;
	int	number;

	i = 0;
	(*stack_head) = (*stack_head)->prev;
	number = (*stack_head)->number;
	(*stack_head)->pos = i;
	i++;
	(*stack_head) = (*stack_head)->next;
	while ((*stack_head)->number != number)
	{
		(*stack_head)->pos = i;
		i++;
		(*stack_head) = (*stack_head)->next;
	}
}

//*****************************************************************************
//*****************************************************************************

void	rotate(t_node **stack_head)
{
	int	i;
	int	number;

	i = 0;
	(*stack_head) = (*stack_head)->next;
	number = (*stack_head)->number;
	(*stack_head)->pos = i;
	i++;
	(*stack_head) = (*stack_head)->next;
	while ((*stack_head)->number != number)
	{
		(*stack_head)->pos = i;
		i++;
		(*stack_head) = (*stack_head)->next;
	}
}

//*****************************************************************************
//*****************************************************************************

void static	move_and_dest_update(t_node **orig, t_node **dest)
{
	int	num;

	if (*dest == NULL)
	{
		(*dest) = (*orig);
		(*orig)->next = (*orig);
		(*orig)->prev = (*orig);
	}
	else
	{
		(*orig)->next = (*dest);
		(*orig)->prev = (*dest)->prev;
		(*dest)->prev->next = (*orig);
		(*dest)->prev = (*orig);
		(*orig)->pos = 0;
		num = (*orig)->number;
		(*orig) = (*orig)->next;
		while ((*orig)->number != num)
		{
			(*orig)->pos++;
			(*orig) = (*orig)->next;
		}
	}
}

//*****************************************************************************
//*****************************************************************************

void	push(t_node **orig, t_node **dest)
{
	t_node	*temp;
	int		num;

	(*orig)->next->prev = (*orig)->prev;
	(*orig)->prev->next = (*orig)->next;
	temp = (*orig)->next;
	move_and_dest_update(orig, dest);
	(*dest) = (*orig);
	if ((*orig)->number == temp->number)
		*orig = NULL;
	else
	{
		(*orig) = temp;
		num = (*orig)->number;
		(*orig)->pos = 0;
		(*orig) = (*orig)->next;
		while ((*orig)->number != num)
		{
			(*orig)->pos--;
			(*orig) = (*orig)->next;
		}
	}
}
