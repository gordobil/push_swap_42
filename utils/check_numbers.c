/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:08 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/09 12:20:21 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dups(char **numbers, char *current, int end)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (numbers[i] != NULL && i < end)
	{
		j = 0;
		count = 0;
		while (current[j] != '\0')
		{
			if (current[j] == numbers[i][j])
				count++;
			j++;
		}
		if (j == count && numbers[i][count] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

int	check_numbers(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		while (numbers[i][j] != '\0')
		{
			if (numbers[i][j] < '0' || numbers[i][j] > '9')
				if (numbers[i][j] != '-' && numbers[i][j] != '\0')
					return (-1);
			j++;
		}
		if (check_dups(numbers, numbers[i], i) != 0)
			return (-1);
		if (ft_atoi(numbers[i]) > INT_MAX || ft_atoi(numbers[i]) < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}
