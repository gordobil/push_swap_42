/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:14:04 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/10 11:35:30 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stacks **stack, int details)
{
	t_stacks	*node;

	node = malloc(sizeof(t_stacks));
	node = *stack;	
	while (node)
	{
		if (details == 1)
			ft_printf("number:%d pointer:%p prev:%p next:%p\n", node->n, node, node->prev, node->next);
		else
		{
			ft_printf("%d", node->n);
			if (node->next != NULL)
				ft_printf (" ");
			else
				ft_printf("/\n");
		}
		node = node->next;
	}
}

void	print_stacks(t_stacks **a, t_stacks **b, int details)
{
	ft_printf("\nSTACK A\n---------------------\n");
	print_stack(a, details);
	ft_printf("\nSTACK B\n---------------------\n");
	if (!*b)
		ft_printf("empty\n");
	else
		print_stack(b, details);
	ft_printf("\n");
}
