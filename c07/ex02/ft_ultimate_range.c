/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:22:28 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/26 10:22:41 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *) malloc((size) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Input into the terminal a min and a max value!\n");
		return (1);
	}
	
	int	*range;
	int	i;
	int	min = atoi(argv[1]);
	int	max = atoi(argv[2]);

	i = 0;
	printf("size of range: %i\n", ft_ultimate_range(&range, min, max));
	while (i < max - min)
	{
		printf("%i ", range[i]);
		i++;
	}
	free(range);
}
*/
