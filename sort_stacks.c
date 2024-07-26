/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:04:11 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/10 13:02:38 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_sort(t_stacks **a, t_stacks **b)
{
	while ((*a != NULL) && (node_count(*a) > 3))
	{
		update_stacks(*b, *a, 'a');
		sort(b, a, 'b', 'a');
	}
	if (node_count(*a) <= 3)
	{
		if (check_if_sorted(*a) != 0)
			sort_2o3(a);
		if (*b == NULL)
			return (1);
	}
	return (0);
}

void	sort_2o3(t_stacks **stack)
{
	update_stacks(*stack, NULL, 'x');
	if ((*stack)->n > (*stack)->next->n
		&& (*stack)->n > (*stack)->next->next->n && node_count(*stack) == 3)
		rotate(stack, NULL, 'a');
	else if ((*stack)->next->n > (*stack)->next->next->n
		&& (*stack)->next->n > (*stack)->n && node_count(*stack) == 3)
		rev_rotate(stack, NULL, 'a');
	if ((*stack)->n > (*stack)->next->n || (node_count(*stack) == 2
			&& (*stack)->n > (*stack)->next->n))
		swap(stack, NULL, 'a');
}

void	sort(t_stacks **s1, t_stacks **s2, char mark1, char mark2)
{
	t_stacks	*s1_mov;
	t_stacks	*s2_mov;

	while (s2_mov->move != 1 && s2_mov)
		s2_mov = s2_mov->next;
	s1_mov = s2_mov->target;
	if (s1_mov->mid == -1 && s2_mov->mid == -1)
		while ((*s1)->n != s1_mov->n && (*s2)->n != s2_mov->n)
			rotate(s1, s2, 'r');
	else if (s1_mov->mid == 1 && s2_mov->mid == 1)
		while ((*s1)->n != s1_mov->n && (*s2)->n != s2_mov->n)
			rev_rotate(s1, s2, 'r');
	if (s1_mov->mid == -1)
		while ((*s1)->n != s1_mov->n)
			rotate(s1, NULL, mark1);
	else if (s1_mov->mid == 1)
		while ((*s1)->n != s1_mov->n)
			rev_rotate(s1, NULL, mark1);
	if (s2_mov->mid == -1)
		while ((*s2)->n != s2_mov->n)
			rotate(s2, NULL, mark2);
	else if (s2_mov->mid == 1)
		while ((*s2)->n != s2_mov->n)
			rev_rotate(s2, NULL, mark2);
	push(s2, s1, mark1);
}

void	last_sort(t_stacks **a)
{
	t_stacks	*smallest;

	update_stacks(*a, NULL, 'x');
	smallest = find_smallest_node(*a);
	while (*a != smallest)
	{
		smallest = find_smallest_node(*a);
		if (smallest->mid == -1)
			rotate(a, NULL, 'a');
		else
			rev_rotate(a, NULL, 'a');
		update_stacks(*a, NULL, 'x');
	}
}
