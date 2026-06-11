/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodes_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:08:23 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:39:51 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_head(t_node **node)
{
	while ((*node)->pos != 0)
		*node = (*node)->next;
	return (*node);
}

//******************************************************************************
//******************************************************************************

void	print_list(t_node *node)
{
	int	i;

	if (node != NULL)
	{
		i = node->number;
		ft_printf("%d - %d - %d\n", node->number, node->pos, node->radix_index);
		node = node->next;
		while (node->number != i)
		{
			ft_printf("%d - %d - %d\n", node->number, node->pos,
				node->radix_index);
			node = node->next;
		}
	}
	else
		ft_printf("Vacio\n");
}

//******************************************************************************
//******************************************************************************

void	full_link(t_node *node)
{
	t_node	*head;
	int		i;

	head = node;
	while (node->next)
		node = node->next;
	node->next = head;
	i = node->pos;
	node = node->next;
	while (node->pos != i)
	{
		node->next->prev = node;
		node = node->next;
	}
	node->next->prev = node;
}

//******************************************************************************
//******************************************************************************

void	delete_list(t_node **node)
{
	t_node	*temp;

	(*node)->prev->next = NULL;
	while (*node)
	{
		temp = (*node);
		*node = (*node)->next;
		free(temp);
	}
}

//******************************************************************************
//******************************************************************************

t_node	*create_node(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
