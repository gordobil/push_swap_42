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

void	update_movement(t_stacks *stack)
{
	t_stacks	*move;

	move = stack;
	while (stack != NULL)
	{
		if (stack->cost <= move->cost)
		{
			move->move = 0;
			stack->move = 1;
			move = stack;
		}
		stack = stack->next;
	}
}

void	update_cost(t_stacks *s1, t_stacks *s2)
{
	int	s1_size;
	int	s2_size;

	s1_size = node_count(s1);
	s2_size = node_count(s2);
	while (s2 != NULL)
	{
		if (s2->mid == 1)
			s2->cost = s2_size - s2->i;
		else
			s2->cost = s2->i;
		if (s2->target->mid == 1)
			s2->cost = s2->cost + (s1_size - s2->target->i);
		else
			s2->cost = s2->cost + s2->target->i;
		s2 = s2->next;
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

void	update_stacks(t_stacks *s1, t_stacks *s2, char stack)
{
	update_index(s1);
	update_index(s2);
	if (s2 != NULL)
	{
		if (stack == 'a')
		{
			update_targets_a(s1, s2);
			free_targets(s1);
		}
		else
		{
			update_targets_b(s1, s2);
			free_targets(s1);
		}
		update_cost(s1, s2);
		update_movement(s2);
	}
	else
		free_targets(s1);
}
