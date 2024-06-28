/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:50:10 by ngordobi          #+#    #+#             */
/*   Updated: 2024/06/24 14:37:39 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//UTILS
int			ft_atoi(const char *str);
int			ft_printf(const char *arg, ...);
int			ft_putchar(char c, int count);
int			ft_putstr(char *str, int count);
int			ft_putnbr(int n, int count);
int			ft_putunbr(unsigned int n, int count);
int			ft_puthex(unsigned long n, int count, char arg_format);
int			ft_putptr(unsigned long p, int count);

#endif
