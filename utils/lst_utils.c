/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:02:24 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/09 13:45:19 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_sorted(t_stacks *stack)
{
	while (stack->next != NULL)
	{
		if (stack->n < stack->next->n)
			stack = stack->next;
		else
			return (-1);
	}
	return (0);
}

int	node_count(t_stacks *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stacks	*find_last_node(t_stacks *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stacks	*find_smallest_node(t_stacks *stack)
{
	t_stacks	*smallest;

	smallest = stack;
	while (stack != NULL)
	{
		if (stack->n < smallest->n)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stacks	*find_biggest_node(t_stacks *stack)
{
	t_stacks	*biggest;

	biggest = stack;
	while (stack != NULL)
	{
		if (stack->n > biggest->n)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}
