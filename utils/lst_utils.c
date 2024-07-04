/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:02:24 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/04 14:33:01 by ngordobi         ###   ########.fr       */
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
