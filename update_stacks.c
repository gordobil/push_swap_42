/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:20 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/10 12:46:30 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_movement(t_stacks *b)
{
	t_stacks	*move;

	move = b;
	while (b != NULL)
	{
		if (b->cost <= move->cost)
		{
			move->move = 0;
			b->move = 1;
			move = b;
		}
		b = b->next;
	}
}

void	update_cost(t_stacks *a, t_stacks *b)
{
	int	a_size;
	int	b_size;

	a_size = node_count(a);
	b_size = node_count(b);
	while (b != NULL)
	{
		if (b->mid == 1)
			b->cost = b_size - b->i;
		else
			b->cost = b->i;
		if (b->target->mid == 1)
			b->cost = b->cost + (a_size - b->target->i);
		else
			b->cost = b->cost + b->target->i;
		b = b->next;
	}
}

void	update_target(t_stacks *a, t_stacks *b)
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

void	update_index(t_stacks *stack)
{
	int			i;
	int			total;

	i = 0;
	total = node_count(stack);
	while (stack)
	{
		stack->i = i;
		if (i + 1 <= total / 2 || (total % 2 != 0 && i <= total / 2))
			stack->mid = -1;
		else
			stack->mid = 1;
		stack->move = 0;
		i++;
		stack = stack->next;
	}
}

void	update_stacks(t_stacks *a, t_stacks *b)
{
	update_index(a);
	update_index(b);
	update_target(a, b);
	update_cost(a, b);
	update_movement(b);
	ft_printf ("\n------Stacks updated------\n");
}
