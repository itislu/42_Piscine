/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:50:51 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/24 09:51:17 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	fact = nb;
	while (nb > 1)
	{
		fact *= (nb - 1);
		nb--;
	}
	return (fact);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input a number!\n");
		return (1);
	}
	printf("%i\n", ft_iterative_factorial(atoi(argv[1])));
}
*/
