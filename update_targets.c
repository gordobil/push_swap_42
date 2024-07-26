/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_targets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:21:24 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/26 11:21:24 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_targets_b(t_stacks *a, t_stacks *b)
{
	t_stacks	*a_node;
	t_stacks	*target;
	int			target_num;

	while (b)
	{
		a_node = a;
		target_num = INT_MAX;
		while (a_node)
		{
			if (a_node->n > b->n && a_node->n < target_num)
			{
				target_num = a_node->n;
				target = a_node;
			}
			a_node = a_node->next;
		}
		if (target_num != INT_MAX)
			b->target = target;
		else
			b->target = find_smallest_node(a);
		b = b->next;
	}
}

void	update_targets_a(t_stacks *b, t_stacks *a)
{
	t_stacks	*b_node;
	t_stacks	*target;
	int			target_num;

	while (a)
	{
		b_node = b;
		target_num = INT_MIN;
		while (b_node)
		{
			if (b_node->n < a->n && b_node->n > target_num)
			{
				target_num = b_node->n;
				target = b_node;
			}
			b_node = b_node->next;
		}
		if (target_num != INT_MIN)
			a->target = target;
		else
			a->target = find_biggest_node(b);
		a = a->next;
	}
}

void	free_targets(t_stacks *stack)
{
	while (stack)
	{
		stack->target = NULL;
		stack->move = 0;
		stack->cost = 0;
		stack = stack->next;
	}
}
