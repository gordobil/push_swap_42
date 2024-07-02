/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:50:19 by ngordobi          #+#    #+#             */
/*   Updated: 2024/02/02 17:38:23 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	w_count(const char *s, char c)
{
	int	i;
	int	count;

	if (c == '\0')
		return (1);
	i = 0;
	while (s[i] == c)
		i++;
	count = 0;
	if (s[i] != '\0')
		count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

int	w_len(const char *s, char c, int j)
{
	int	count;

	count = 0;
	if (s[0] == '\0')
		return (1);
	while (s[j] == c)
		j++;
	while (s[j] != c && s[j] != '\0')
	{
		count++;
		j++;
	}
	return (count);
}

int	w_start(const char *s, char c, int j, int word_l)
{
	j = j + word_l;
	if (s[j] == '\0')
		return (j);
	while (s[j] == c)
		j++;
	return (j);
}

char	**matrix_errors(char **matrix, int i, int mark)
{
	if (mark == 1)
	{
		i = 0;
		matrix[i] = NULL;
		matrix[i + 1] = NULL;
		return (matrix);
	}
	else
	{
		while (i-- >= 0)
			matrix[i] = NULL;
		return (NULL);
	}
}

char	**ft_split(const char *s, char c)
{
	int		word_c;
	int		word_l;
	int		i;
	int		j;
	char	**matrix;

	word_c = w_count(s, c);
	matrix = malloc(sizeof(char *) * (word_c + 1));
	if (!matrix || !s)
		return (NULL);
	i = -1;
	j = 0;
	word_l = 0;
	while (++i < word_c)
	{
		j = w_start(s, c, j, word_l);
		word_l = w_len(s, c, j);
		if (s[0] == '\0')
			return (matrix_errors(matrix, i, 1));
		matrix[i] = ft_substr(s, j, word_l);
		if (!matrix[i] || matrix[i] == NULL)
			return (matrix_errors(matrix, i, 2));
	}
	matrix[i] = NULL;
	return (matrix);
}
