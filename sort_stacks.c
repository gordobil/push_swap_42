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
	while ((*b)->move != 1 && *b)
		*b = (*b)->next;
	while (*a != (*b)->target)
		*a = (*a)->next;
	if ((*a)->mid == -1 && (*b)->mid == -1)
		while ((*a)->prev != NULL || (*b)->prev != NULL)
			rotate(a, b, 'r');
	else if ((*a)->mid == 1 && (*b)->mid == 1)
		while ((*a)->prev != NULL || (*b)->prev != NULL)
			rev_rotate(a, b, 'r');
	if ((*a)->mid == -1)
		while ((*a)->prev != NULL)
			rotate(a, NULL, 'a');
	else if ((*a)->mid == 1)
		while ((*a)->prev != NULL)
			rev_rotate(a, NULL, 'a');
	if ((*b)->mid == -1)
		while ((*b)->prev != NULL)
			rotate(b, NULL, 'b');
	else if ((*b)->mid == 1)
		while ((*b)->prev != NULL)
			rev_rotate(b, NULL, 'b');
	push(b, a, 'a');
}
