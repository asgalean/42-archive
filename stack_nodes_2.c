/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodes_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:08:30 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:39:51 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list_str(t_node **stack_a, char *string)
{
	int		i;
	char	**input_matrix;
	t_node	*new_node;
	t_node	*previous;

	input_matrix = ft_split(string, ' ');
	i = -1;
	while (input_matrix[++i])
	{
		new_node = create_node();
		new_node->number = simple_atoi(input_matrix[i]);
		new_node->pos = i;
		if (i == 0)
		{
			*stack_a = new_node;
			previous = new_node;
		}
		else
		{
			previous->next = new_node;
			previous = new_node;
		}
	}
	free_matrix(input_matrix);
}

//******************************************************************************
//******************************************************************************

void	create_list_arg(t_node **stack_a, char **inputs, int argc)
{
	int		i;
	t_node	*new_node;
	t_node	*previous;

	i = -1;
	while (++i + 1 < argc)
	{
		new_node = create_node();
		new_node->number = simple_atoi(inputs[i + 1]);
		new_node->pos = i;
		if (i == 0)
		{
			*stack_a = new_node;
			previous = new_node;
		}
		else
		{
			previous->next = new_node;
			previous = new_node;
		}
	}
}

//******************************************************************************
//******************************************************************************

int	list_len(t_node *node)
{
	int	len;
	int	init_pos;

	len = 1;
	init_pos = node->pos;
	node = node->next;
	while (node->pos != 0)
	{
		node = node->next;
		len++;
	}
	return (len);
}

//******************************************************************************
//******************************************************************************

int	check_dupes(t_node *node)
{
	int		len;
	int		i;
	t_node	*temp;

	i = 0;
	len = list_len(node);
	while (i < len)
	{
		temp = node->next;
		while (temp->pos != node->pos)
		{
			if (node->number == temp->number)
				return (ft_printf("Error\n"), 0);
			temp = temp->next;
		}
		node = node->next;
		i++;
	}
	return (1);
}

//******************************************************************************
//******************************************************************************

int	check_sorted(t_node *node)
{
	t_node	*temp;

	temp = node;
	while (temp->next->pos != node->pos)
	{
		if (temp->next->pos != node->pos && temp->number > temp->next->number)
			return (1);
		temp = temp->next;
	}
	return (ft_printf(""), 0);
}
