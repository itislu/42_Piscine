/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:25:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/10 12:25:20 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	position;
	int	swapspace;

	position = 0;
	while (position < (size / 2))
	{
		swapspace = tab[position];
		tab[position] = tab[size - 1 - position];
		tab[size - 1 - position] = swapspace;
		position++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
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
	
	// Let the function reverse the array
	ft_rev_int_tab(tab, argc - 1);
	
	// Print the now reversed array
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
