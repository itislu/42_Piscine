/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:02:27 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/07 18:03:54 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swapspace1;
	int	swapspace2;

	swapspace1 = *a;
	swapspace2 = *b;
	*a = swapspace2;
	*b = swapspace1;
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input two numbers!\n");
		return (1);
	}
	
	int	a;
	int	b;

	a = atoi (argv[1]);
	b = atoi (argv[2]);
	
	ft_swap(a, b);
	
	printf("a: %i\nb: %i\n", a, b);
}
*/
