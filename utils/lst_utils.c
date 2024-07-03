/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:02:24 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/03 14:20:07 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*find_last_node(t_stacks *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_new_node(t_stacks **stack, int n)
{
	t_stacks	*new_node;
	t_stacks	*last_node;

	if (!stack)
		return ;
	ft_printf("1\n");
	new_node = malloc(sizeof(t_stacks));
	ft_printf("2\n");
	if (!new_node)
		return ;
	ft_printf("3\n");
	new_node->next = NULL;
	new_node->n = n;
	ft_printf("%p\n", *stack);
	if (*stack)
	{
		ft_printf("5\n");
		*stack = new_node;
		ft_printf("6\n");
		new_node->prev = NULL;
		ft_printf("7\n");
	}
	else
	{
		ft_printf("8\n");
		last_node = find_last_node(*stack);
		ft_printf("9\n");
		last_node->next = new_node;
		ft_printf("10\n");
		new_node->prev = last_node;
		ft_printf("11\n");
	}
	ft_printf("n:%d a:%p ap:%p an:%p\n", new_node->n, new_node, new_node->prev, new_node->next);
}