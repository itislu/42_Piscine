/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:55:34 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/26 09:58:17 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = (int *) malloc((size) * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Input into the terminal a min and a max value!\n");
		return (1);
	}

	int	*test;
	int	i;
	int	min = atoi(argv[1]);
	int	max = atoi(argv[2]);

	i = 0;
	test = ft_range(min, max);
	while (i < max - min)
	{
		printf("%i ", test[i]);
		i++;
	}
	printf("\n");
	free(test);
}
*/
