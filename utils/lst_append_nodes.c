/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_append_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:36:33 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/04 16:34:41 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	append_node_end(t_stacks **stack, int nbr, char delete)
{
	t_stacks	*new_node;
	t_stacks	*last_node;
	
	new_node = malloc(sizeof(t_stacks));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->n = nbr;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	delete_node(*stack, delete);
}

void	append_node_start(t_stacks **stack, int nbr, char delete)
{
	t_stacks	*new_node;
	t_stacks	*first_node;
	
	first_node = *stack;
	new_node = malloc(sizeof(t_stacks));
	new_node->n = nbr;
	new_node->prev = NULL;
	new_node->next = first_node;
	first_node->prev = new_node;
	*stack = new_node;
	delete_node(*stack, delete);
}

void	delete_node(t_stacks *stack, char position)
{
	if (position == 's')
	{
		stack = stack->next;
		stack->prev = NULL;
	}
	else if (position == 'e')
	{
		stack = find_last_node(stack);
		stack = stack->prev;
		stack->next = NULL;
	}
}