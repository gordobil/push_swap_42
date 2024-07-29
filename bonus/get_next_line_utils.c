/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:29 by ngordobi          #+#    #+#             */
/*   Updated: 2024/03/11 11:48:29 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = s;
	while (s2[i] != c && s2[i] != '\0')
		i++;
	if (s2[i] == c)
		return (s2);
	return (NULL);
}
