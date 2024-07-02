/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:44:26 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/02 14:19:49 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_stacks	*load_a(char **numbers)
{
	t_stacks	*a;
	t_stacks	*temp_p;
	t_stacks	*first;
	int			i;

	i = 1;
	while (numbers[i] != NULL)
	{
		a->n = ft_atoi(numbers[i]);
		a->i = i;
		if (i == 1)
			first = a;
		else
			a->prev = temp_p;
		temp_p = a;
		a = a->next;
		i++;
	}
	first->prev = temp_p;
	return (a);
}*/

int	main(int argc, char **argv)
{
	t_stacks	*a;
	t_stacks	*b;
	int	i = 0;

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
	//a = load_a(argv);
	b = NULL;
	return (0);
}
