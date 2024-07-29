/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:16:53 by ngordobi          #+#    #+#             */
/*   Updated: 2024/07/29 10:16:53 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* void	checker(char **numbers, char **inst)
{

} */

char	**get_instructions()
{
	char	*inst;
	int		rd;
	int		i;

	rd = 1;
	i = 0;
	while (rd >= 0)
	{
		rd = read(0, inst, 20);
	}
	ft_printf("%s", inst);
	ft_printf("%d\n", i);
}

int	main(int argc, char **argv)
{
	char	**inst;

	if (argc < 2 || (argc >= 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split (argv[1], ' ');
	else
		argv++;
	if (argv == NULL || check_numbers(argv) != 0 || argv[0] == NULL
		|| argv[1] == NULL)
		return (0);
	inst = get_instructions();
	// checker(argv, inst);
	return (0);
}
