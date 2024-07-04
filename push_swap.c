/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:44:26 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/04 16:34:22 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_stack_a(t_stacks **stack, char **numbers)
{
	int	i;
	int	n;

	i = 0;
	while (numbers[i])
	{
		n = ft_atoi(numbers[i]);
		append_node_end(stack, n, '0');
		i++;
	}
}

void	push_swap(char **numbers)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	load_stack_a(&stack_a, numbers);
	print_stack(&stack_a);
	ft_printf("%d\n", node_count(stack_a));
	
	append_node_end(&stack_a, 0, 0);
	print_stack(&stack_a);
	ft_printf("%d\n", node_count(stack_a));
	
	delete_node(stack_a, 'e');
	print_stack(&stack_a);
	ft_printf("%d\n", node_count(stack_a));
	
	append_node_start(&stack_a, 0, 0);
	print_stack(&stack_a);
	ft_printf("%d\n", node_count(stack_a));
	
	delete_node(stack_a, 's');
	print_stack(&stack_a);
	ft_printf("%d\n", node_count(stack_a));
	while (check_if_sorted(stack_a) != 0)
	{
		if (node_count(stack_a) == 2)
			ft_printf("%d\n", node_count(stack_a));
		else if (node_count(stack_a) == 3)
			ft_printf("%d\n", node_count(stack_a));
		else
			ft_printf("%d\n", node_count(stack_a));
		break ;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2 || (argc >= 2 && !argv[1][0]))
	{
		ft_printf ("Error\nInvalid number of arguments passed\n");
		return (0);
	}
	if (argc == 2)
		argv = ft_split (argv[1], ' ');
	else
		argv++;
	if (argv == NULL || check_numbers(argv) != 0)
	{
		ft_printf ("Error\nInvalid argument found\n");
		return (0);
	}
	push_swap(argv);
	return (0);
}
