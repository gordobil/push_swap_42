/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:11:17 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/19 11:05:32 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putptr(unsigned long p, int count)
{
	count = ft_putstr("0x", count);
	if (p == 0)
		count = ft_putchar('0', count);
	else
		count = ft_puthex(p, count, 'x');
	return (count);
}
