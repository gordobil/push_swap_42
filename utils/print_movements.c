/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:48:20 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/09 13:40:25 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_movements(char *movement, char stack)
{
	if ((movement[0] == 'p' && movement[1] == '\0' && (stack == 'a'
				|| stack == 'b')) || (movement[0] == 's' && movement[1] == '\0'
			&& (stack == 'a' || stack == 'b' || stack == 's'))
		|| (movement[0] == 'r' && movement[1] == '\0' && (stack == 'a'
				|| stack == 'b' || stack == 'r')) || (movement[0] == 'r'
			&& movement[1] == 'r' && movement[2] == '\0' && (stack == 'a'
				|| stack == 'b' || stack == 'r')))
	{
		ft_printf("%s%c\n", movement, stack);
		return (0);
	}
	else
	{
		ft_printf("Error\nMovement error\n");
		return (-1);
	}
}
