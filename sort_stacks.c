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

void	sort_2o3(t_stacks **stack)
{
	if ((*stack)->n > (*stack)->next->n &&
		(*stack)->n > (*stack)->next->next->n && node_count(*stack) == 3)
		rotate(stack, NULL, 'a');
	else if ((*stack)->next->n > (*stack)->next->next->n &&
			(*stack)->next->n > (*stack)->n &&	node_count(*stack) == 3)
		rev_rotate(stack, NULL, 'a');
	if ((*stack)->n > (*stack)->next->n || node_count(*stack) == 2)
		swap(stack, NULL, 'a');
}

void	sort(t_stacks **a, t_stacks **b)
{
	t_stacks	*a_mov;
	t_stacks	*b_mov;

	a_mov = *a;
	b_mov = *b;
	while (b_mov->move != 1 && b_mov)
		b_mov = b_mov->next;
	while (a_mov != b_mov->target && a_mov)
		a_mov = a_mov->next;
	if (a_mov->mid == -1 && b_mov->mid == -1)
		while ((*a)->n != a_mov->n && (*b)->n != b_mov->n)
			rotate(a, b, 'r');
	else if (a_mov->mid == 1 && b_mov->mid == 1)
		while ((*a)->n != a_mov->n && (*b)->n != b_mov->n)
			rev_rotate(a, b, 'r');
	if (a_mov->mid == -1)
		while ((*a)->n != a_mov->n)
			rotate(a, NULL, 'a');
	else if (a_mov->mid == 1)
		while ((*a)->n != a_mov->n)
			rev_rotate(a, NULL, 'a');
	if (b_mov->mid == -1)
		while ((*b)->n != b_mov->n)
			rotate(b, NULL, 'b');
	else if (b_mov->mid == 1)
		while ((*b)->n != b_mov->n)
			rev_rotate(b, NULL, 'b');
	push(b, a, 'a');
}

void	last_sort(t_stacks **a)
{
	t_stacks	*smallest;

	smallest = find_smallest_node(*a);
	while (*a != smallest)
	{
		smallest = find_smallest_node(*a);
		if (smallest->mid == -1)
			rotate(a, NULL, 'a');
		else
			rev_rotate(a, NULL, 'a');
		update_stacks(*a, NULL);
	}
}
