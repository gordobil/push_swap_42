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

typedef struct s_stacks
{
	int					n;
	struct s_stacks		*prev;
	struct s_stacks		*next;
}				t_stacks;

//MAIN
int				check_numbers(char **numbers);
int				swap(t_stacks **stack, t_stacks **stack2, char mov);
int				push(t_stacks **src, t_stacks **dst, char mov);
int				rotate(t_stacks **stack, t_stacks **stack2, char mov);
int				rev_rotate(t_stacks **stack, t_stacks **stack2, char mov);

//UTILS
long			ft_atoi(const char *str);
char			**ft_split(const char *s, char c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_printf(const char *arg, ...);
int				ft_putchar(char c, int count);
int				ft_putstr(char *str, int count);
int				ft_putnbr(int n, int count);
int				ft_putunbr(unsigned int n, int count);
int				ft_puthex(unsigned long n, int count, char arg_format);
int				ft_putptr(unsigned long p, int count);
int				put_movement(char *movement, char stack);

//LST_UTILS
int				load_stack(t_stacks **stack, char **numbers);
int				append_node_end(t_stacks **stack, int nbr);
int				append_node_start(t_stacks **stack, int nbr);
void			delete_node(t_stacks **stack, char positions);
t_stacks		*find_last_node(t_stacks *stack);
int				check_if_sorted(t_stacks *stack);
int				node_count(t_stacks *stack);
void			print_stack(t_stacks **stack);

#endif
