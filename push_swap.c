/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:38:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/08 13:38:10 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stacks	*stack_a;
	t_stacks	*stack_b;
	char	**b;

	b = malloc(5 * sizeof(char*));
	b[0] = "21";
	b[1] = "22";
	b[2] = "23";
	b[3] = "24";
	b[4] = NULL;
	stack_a = NULL;
	stack_b = NULL;
	load_stack(&stack_a, numbers);
	load_stack(&stack_b, b);
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));
	
	swap(&stack_a, &stack_b, 's');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	swap(&stack_a, NULL, 'a');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	swap(&stack_b, NULL, 'b');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	push(&stack_b, &stack_a, 'a');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	push(&stack_a, &stack_b, 'b');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	rotate(&stack_a, NULL, 'a');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	rotate(&stack_b, NULL, 'b');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	rotate(&stack_a, &stack_b, 'r');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	rev_rotate(&stack_a, NULL, 'a');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	rev_rotate(&stack_b, NULL, 'b');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	rev_rotate(&stack_a, &stack_b, 'r');
	print_stack(&stack_a);
	ft_printf("nodes a:%d\n\n", node_count(stack_a));
	print_stack(&stack_b);
	ft_printf("nodes b:%d\n\n", node_count(stack_b));

	/* while (check_if_sorted(stack_a) != 0)
	{
		if (node_count(stack_a) == 2)
			ft_printf("%d\n", node_count(stack_a));
		else if (node_count(stack_a) == 3)
			ft_printf("%d\n", node_count(stack_a));
		else
			ft_printf("%d\n", node_count(stack_a));
		break ;
	} */
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
