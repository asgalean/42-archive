/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:52:34 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:52:35 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				number;
	int				pos;
	int				radix_index;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

//List handling
t_node	*create_node(void);
void	create_list_str(t_node **stack_a, char *string);
void	create_list_arg(t_node **stack_a, char **inputs, int argc);
void	delete_list(t_node **node);
void	full_link(t_node *node);
void	print_list(t_node *node);
void	print_node(t_node **node);
t_node	*find_head(t_node **node);

int		list_len(t_node *node);

//Moves
void	swap(t_node	**stack_head);
void	rotate(t_node **stack_head);
void	reverse_rotate(t_node **stack_head);
void	push(t_node **orig, t_node **dest);

//Stack specific moves
void	swap_a(t_node **stack_head);
void	push_a(t_node **stack_b, t_node **stack_a);
void	rotate_a(t_node **stack_head);
void	reverse_rotate_a(t_node **stack_head);

void	swap_b(t_node **stack_head);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate_b(t_node **stack_head);
void	reverse_rotate_b(t_node **stack_head);

void	swap_all(t_node **stack_a, t_node **stack_b);
void	rotate_all(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_all(t_node **stack_a, t_node **stack_b);

//Utilities
void	free_matrix(char **matrix);
int		pseudo_atoi(char *number, int *is_int);
int		is_valid_number(char *number);
int		parse_string(char *input);
int		parse_inputs(int argc, char **inputs);
int		simple_atoi(char *number);
char	**ft_split(char const *s, char c);

int		check_dupes(t_node *node);
int		check_sorted(t_node *node);
int		check_ok(t_node *stack_a);

//Sort
void	small_sort(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);

void	small_sort(t_node **stack_a, t_node **stack_b);
void	sorting(t_node **stack_a, t_node **stack_b);

int		find_insertion_position(t_node *stack_a, int num_to_insert);
int		find_min_position(t_node *stack);

//Radix
void	radix_index_get(t_node *stack);
void	babburu_sorto(int *array, int len);
void	radix_sort(t_node **stack_a, t_node **stack_b);

#endif
