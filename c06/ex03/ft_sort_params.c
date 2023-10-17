/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:22:03 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/25 01:23:55 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sort(char **param, int stop);
int		ft_strcmp(char *curr_str, char *prev_str);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	sort(argv, argc);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

/* Swap the array indices */
void	sort(char **param, int stop)
{
	int	i;

	i = 2;
	while (i < stop)
	{
		if (ft_strcmp(param[i], param[i - 1]) < 0)
		{
			param[0] = param[i];
			param[i] = param[i - 1];
			param[i - 1] = param[0];
			sort(param, i);
		}
		i++;
	}
}

int	ft_strcmp(char *curr_str, char *prev_str)
{
	int	i;

	i = 0;
	while (curr_str[i] == prev_str[i] && curr_str[i])
		i++;
	return (curr_str[i] - prev_str[i]);
}
