/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:13:23 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/09 19:13:26 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	x;
	int	y;

	if (*b == 0)
		return ;
	x = *a;
	y = *b;
	*a = x / y;
	*b = x % y;
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input 2 numbers!\n");
		return (1);
	}
	
	int	a;
	int	b;

	a = atoi (argv[1]);
	b = atoi (argv[2]);
	
	ft_ultimate_div_mod(&a, &b);
	
	if (b != 0)
		printf("a / b = %i\nremainder: %i\n", a, b);
}
*/
