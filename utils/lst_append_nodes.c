/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_append_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:36:33 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/09 14:10:24 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	append_node_end(t_stacks **stack, int nbr)
{
	t_stacks	*new_node;
	t_stacks	*last_node;
	
	new_node = malloc(sizeof(t_stacks));
	if (!new_node || !stack)
	{
		ft_printf("Error\nError appending node\n");
		return (-1);
	}
	new_node->next = NULL;
	new_node->n = nbr;
	if (!(*stack) || stack == NULL)
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
	return (0);
}

/* int	append_node_start(t_stacks **stack, int nbr)
{
	t_stacks	*new_node;
	t_stacks	*first_node;
	
	first_node = *stack;
	new_node = malloc(sizeof(t_stacks));
	if (!new_node || !stack)
	{
		ft_printf("Error\nError appending node\n");
		return (-1);
	}
	new_node->n = nbr;
	new_node->prev = NULL;
	new_node->next = first_node;
	first_node->prev = new_node;
	*stack = new_node;
	return (0);
}
 */