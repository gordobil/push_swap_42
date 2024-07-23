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
	int			mov;

	a = NULL;
	b = NULL;
	mov = 0;
	load_stack(&a, numbers);
	print_stacks(&a, &b, 1);
	update_stacks(a, b);
	while (node_count(a) > 3)
		push(&a, &b, 'b');
	// if (check_if_sorted(a) != 0)
	//  	sort_2o3(&a);
	while (b != NULL)
	{
		update_stacks(a, b);
		print_stacks(&a, &b, 1);
		sort(a, b);
		// while (b->prev != NULL)
		// 	b = b->prev;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2 || (argc >= 2 && !argv[1][0]))
	{
		ft_printf ("Error\nInvalid arguments\n");
		return (0);
	}
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
