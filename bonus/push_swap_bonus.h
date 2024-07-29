/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:02:01 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/29 11:02:01 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include "../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//BONUS


//GET NEXT LINE
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(char *s, int c);

#endif