/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:54:06 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/09 14:37:35 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_2(t_stacks **stack, void *node1, void *node3, int node_c)
{
	if (node_c > 2)
	{
		(*stack)->next->next = node3;
		(*stack)->next->next->prev = node1;
	}
	else
		(*stack)->next->next = NULL;
	(*stack)->prev = NULL;
}

int	swap(t_stacks **stack, t_stacks **stack2, char mov)
{
	void	*node1;
	void	*node2;
	void	*node3;
	int		n[2];
	int		node_c;

	node_c = node_count(*stack);
	if (node_c <= 1 || stack == NULL || !stack)
		return (-1);
	node1 = *stack;
	node2 = (*stack)->next;
	node3 = (*stack)->next->next;
	n[0] = (*stack)->n;
	n[1] = (*stack)->next->n;
	*stack = node2;
	(*stack)->n = n[1];
	(*stack)->next = node1;
	(*stack)->next->prev = node2;
	(*stack)->next->n = n[0];
	swap_2(stack, node1, node3, node_c);
	if (mov == 's' && stack2 != NULL)
		return (swap(stack2, NULL, mov));
	else
		return (print_movements("s", mov));
}

int	push(t_stacks **src, t_stacks **dst, char mov)
{
	t_stacks	*dst_first;

	if (src == NULL || !(*src))
		return (-1);
	dst_first = *dst;
	*dst = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	(*dst)->next = dst_first;
	(*dst)->prev = NULL;
	if (dst_first != NULL)
		dst_first->prev = *dst;
	return (print_movements("p", mov));
}

int	rotate(t_stacks **stack, t_stacks **stack2, char mov)
{
	t_stacks	*node;
	t_stacks	*last_node;

	if (!stack || *stack == NULL)
		return (-1);
	node = *stack;
	last_node = find_last_node(*stack);
	if (*stack == last_node)
		return (0);
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	last_node->next = node;
	node->prev = last_node;
	node->next = NULL;
	if (mov == 'r' && stack2 != NULL)
		return (rotate(stack2, NULL, mov));
	else
		return (print_movements("r", mov));
}

int	rev_rotate(t_stacks **stack, t_stacks **stack2, char mov)
{
	t_stacks	*node;
	t_stacks	*last_node;

	if (!stack || *stack == NULL)
		return (-1);
	node = *stack;
	last_node = find_last_node(*stack);
	if (*stack == last_node)
		return (0);
	*stack = last_node;
	node->prev = last_node;
	(*stack)->next = node;
	last_node->prev->next = NULL;
	(*stack)->prev = NULL;
	if (mov == 'r' && stack2 != NULL)
		return (rev_rotate(stack2, NULL, mov));
	else
		return (print_movements("rr", mov));
}
