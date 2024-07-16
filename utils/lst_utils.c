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
	int	sorted;

	sorted = 0;
	while (sorted == 0)
	{
		if (stack->n < stack->next->n)
			stack = stack->next;
		else
		{
			sorted = -1;
			break ;
		}
	}
	return (sorted);
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

void	delete_node(t_stacks **stack, char position)
{
	if (position == 's')
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else if (position == 'e')
	{
		*stack = find_last_node(*stack);
		*stack = (*stack)->prev;
		free((*stack)->next);
		(*stack)->next = NULL;
		while ((*stack)->prev != NULL)
			*stack = (*stack)->prev;
	}
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

	// t_stacks	*node;

	// if (position == 's')
	// {
	// 	node = *stack;
	// 	*stack = (*stack)->next;
	// 	free(node);
	// 	node = NULL;
	// 	(*stack)->prev = NULL;
	// }