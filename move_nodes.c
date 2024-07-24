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

int	swap(t_stacks **stack, t_stacks **stack2, char mov)
{
	void	*node1;
	void	*node2;
	void	*node3;
	int		n1;
	int		n2;

	if (node_count(*stack) <= 1 || stack == NULL || !stack)
		return (-1);
	node1 = *stack;
	node2 = (*stack)->next;
	node3 = (*stack)->next->next;
	n1 = (*stack)->n;
	n2 = (*stack)->next->n;
	*stack = node2;
	(*stack)->n = n2;
	(*stack)->next = node1;
	(*stack)->next->prev = node2;
	(*stack)->next->n = n1;
	(*stack)->next->next = node3;
	(*stack)->next->next->prev = node1;
	(*stack)->prev = NULL;
	if (mov == 's' && stack2 != NULL)
		return (swap(stack2, NULL, mov));
	else
		return (print_movements("s", mov));
}

/* int	push2(t_stacks **src, t_stacks **dst, char mov)
{
    t_stacks    *dst_first;

	dst_first = NULL;
	if (src == NULL || !(*src))
		return (-1);
	if (dst == NULL)
		append_node_end(dst, (*src)->n);
	else
	{
		dst_first = *dst;
    	*dst = *src;
	}
    *src = (*src)->next;
	if (*src != NULL)
	
		(*src)->prev = NULL;
	(*dst)->next = dst_first;
	(*dst)->prev = NULL;
	if (dst_first != NULL)
		dst_first->prev = *dst;	
	return (print_movements("p", mov));
}

int	push(t_stacks **src, t_stacks **dst, char mov)
{
	if (src == NULL || !(*src))
		return (-1);
	if (dst == NULL || !(*dst))
		append_node_end(dst, (*src)->n);
	else
		append_node_start(dst, (*src)->n);
	delete_node(src, 's');
	return (print_movements("p", mov));
}

int	rotate(t_stacks **stack, t_stacks **stack2, char mov)
{
	if (!stack || *stack == NULL)
		return (-1);
	append_node_end(stack, (*stack)->n);
	delete_node(stack, 's');
	if (mov == 'r' && stack2 != NULL)
		return (rotate(stack2, NULL, mov));
	else
		return (print_movements("r", mov));
}

int	rev_rotate(t_stacks **stack, t_stacks **stack2, char mov)
{
	t_stacks	*node;

	node = find_last_node(*stack);
	append_node_start(stack, node->n);
	delete_node(stack, 'e');
	if (mov == 'r' && stack2 != NULL)
		return (rev_rotate(stack2, NULL, mov));
	else
		return (print_movements("rr", mov));
} */




int	push(t_stacks **src, t_stacks **dst, char mov)
{
    t_stacks    *dst_first;

	if (src == NULL || !(*src))
		return (-1);
    dst_first=*dst;
    *dst=*src;
    *src=(*src)->next;
    if (*src != NULL) 
        (*src)->prev=NULL;
    (*dst)->next=dst_first;
    (*dst)->prev=NULL;
    if (dst_first != NULL)
		dst_first->prev = *dst;	
	return (print_movements("p", mov));
}

int	rotate(t_stacks **stack, t_stacks **stack2, char mov)
{
	t_stacks *stack_aux;
	t_stacks *last_node;

    if (!stack || *stack == NULL)
		return (-1);
    stack_aux=*stack;
    last_node=find_last_node(*stack);
    if (*stack == last_node)
        return (0);
    *stack=(*stack)->next;
    if (*stack != NULL) 
        (*stack)->prev=NULL;
    last_node->next=stack_aux;
    stack_aux->prev=last_node;
    stack_aux->next=NULL;
	if (mov == 'r' && stack2 != NULL)
		return (rotate(stack2, NULL, mov));
	else
		return (print_movements("r", mov));

}

int	rev_rotate(t_stacks **stack, t_stacks **stack2, char mov)
{
	t_stacks *stack_aux;
	t_stacks *last_node;

    if (!stack || *stack == NULL)
		return (-1);
    stack_aux=*stack;
    last_node=find_last_node(*stack);
    if (*stack == last_node)
        return (0);
    *stack=last_node;
    stack_aux->prev=last_node;
    (*stack)->next=stack_aux;
    last_node->prev->next=NULL;
    (*stack)->prev=NULL;
	if (mov == 'r' && stack2 != NULL)
		return (rev_rotate(stack2, NULL, mov));
	else
		return (print_movements("r", mov));

}
