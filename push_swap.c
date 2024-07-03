/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:44:26 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/03 14:01:22 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_a(t_stacks **stack_a, char **numbers)
{
	int			i;
	int			n;

	i = 1;
	while (numbers[i])
	{
		n = ft_atoi(numbers[i]);
		ft_printf("n:%d\n", n);
		append_new_node(stack_a, n);
		i++;
	}
}

void	push_swap(char **numbers)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	load_a(&stack_a, numbers);
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
	if (argv == NULL || check_numbers(argv) != 0)
	{
		ft_printf ("Error\nInvalid argument found\n");
		return (0);
	}
	push_swap(argv);
	return (0);
}
