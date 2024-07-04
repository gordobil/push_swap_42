/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:14:04 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/04 15:30:16 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stacks **stack)
{
	t_stacks	*node;

	node = malloc(sizeof(t_stacks));
	node = *stack;	
	while (node)
	{
		ft_printf("number:%d pointer:%p prev:%p next:%p\n", node->n, node, node->prev, node->next);
		node = node->next;
	}
}