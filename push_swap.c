/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:44:26 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/28 13:41:44 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*load_a(int size, char **numbers)
{
	int	*a;
	int	i;
	int	j;
	int	k;

	a = malloc(size * sizeof(int));
	if (!a)
		return (NULL);
	k = 0;
	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		while (numbers[i][j] != '\0')
		{
			if (numbers[i][j] < '0' || numbers[i][j] > '9')
				return (NULL);
			j++;	
		}
		a[k] = ft_atoi(numbers[i]);
		k++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;

	if (argc < 3 || !argv)
		return (ft_printf("Error\nInvalid arguments\n"), 0);
	a = load_a(argc - 1, argv);
	if (a == NULL)
		return (ft_printf("Error\nError in arguments"), 0);
	return (0);
}