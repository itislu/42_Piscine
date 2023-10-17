/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:44:54 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/10 20:44:56 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	swapspace;
	int	i;

	i = 1;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			swapspace = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = swapspace;
			ft_sort_int_tab(tab, i);
		}
		i++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	// Check if user gave input
	if (argc < 2)
	{
		printf("Input numbers!");
		return (1);
	}	

	int	tab[argc - 1];
	int	i;

	// Convert argv's char array to new int array called tab
	i = 0;
	while (i < argc - 1)
	{
		tab[i] = atoi(argv[i + 1]);
		i++;
	}
	
	// Let the function sort the array
	ft_sort_int_tab(tab, argc - 1);
	
	// Print the now sorted array
	i = 0;
	while (i < argc - 1)
	{
		printf("%i ", tab[i]);
		i++;
	}
	printf("\n");
	
	return (0);
}
*/
