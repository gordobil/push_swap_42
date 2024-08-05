/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:38:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/10 13:02:50 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	load_stack(t_stacks **stack, char **numbers)
{
	int	i;
	int	n;

	i = 0;
	while (numbers[i])
	{
		n = ft_atoi(numbers[i]);
		if (append_node_end(stack, n) == -1)
			return (-1);
		i++;
	}
	return (0);
}

void	push_swap(char **numbers)
{
	t_stacks	*a;
	t_stacks	*b;

	a = NULL;
	b = NULL;
	load_stack(&a, numbers);
	if (check_if_sorted(a) == 0)
		return ;
	while ((node_count(a) > 3) && (node_count(b) <= 2))
		push(&a, &b, 'b');
	if (first_sort(&a, &b) == 1)
		return ;
	while (b != NULL)
	{
		update_stacks(a, b, 'b');
		sort(&a, &b, 'a', 'b');
	}
	update_stacks(a, b, 'b');
	if (check_if_sorted(a) != 0)
		last_sort(&a);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || (argc >= 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split (argv[1], ' ');
	else
		argv++;
	if (argv == NULL || check_numbers(argv) != 0 || argv[0] == NULL
		|| argv[1] == NULL)
	{
		ft_printf ("Error\nInvalid arguments\n");
		return (0);
	}
	push_swap(argv);
	return (0);
}
