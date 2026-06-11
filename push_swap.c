/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:08:02 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:52:20 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *number)
{
	int	i;
	int	is_int;

	i = 0;
	is_int = 1;
	if (number[i] != '-' && number[i] != '+'
		&& !('0' <= number[i] && number[i] <= '9'))
		return (0);
	if ((number[i] == '-' || number[i] == '+')
		&& !('0' <= number[i + 1] && number[i + 1] <= '9'))
		return (0);
	i++;
	while (number[i] != '\0')
	{
		if (!('0' <= number[i] && number[i] <= '9'))
			return (0);
		i++;
	}
	i = pseudo_atoi(&number[0], &is_int);
	if (is_int == 0)
		return (0);
	return (1);
}

//******************************************************************************
//******************************************************************************

void	small_sort(t_node **stack_a, t_node **stack_b)
{
	if (list_len(*stack_a) == 2)
		swap_a(stack_a);
	if (list_len(*stack_a) == 3)
		sort_three(stack_a);
	if (list_len(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	if (list_len(*stack_a) == 5)
		sort_five(stack_a, stack_b);
}

//******************************************************************************
//******************************************************************************

int	check_ok(t_node *stack_a)
{
	int	is_ok;

	is_ok = 1;
	if (!check_dupes(stack_a))
		is_ok = 0;
	if (!check_sorted(stack_a))
		is_ok = 0;
	return (is_ok);
}

//******************************************************************************
//******************************************************************************

void	sorting(t_node **stack_a, t_node **stack_b)
{
	if (list_len(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

//******************************************************************************
//******************************************************************************

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (!parse_string(argv[1]))
			return (0);
		create_list_str(&stack_a, argv[1]);
	}
	else if (argc > 2)
	{
		if (!parse_inputs(argc, argv))
			return (0);
		create_list_arg(&stack_a, argv, argc);
	}
	else
		return (ft_printf(""), 0);
	full_link(stack_a);
	if (!check_ok(stack_a))
		return (delete_list(&stack_a), 0);
	radix_index_get(stack_a);
	sorting(&stack_a, &stack_b);
	delete_list(&stack_a);
}
