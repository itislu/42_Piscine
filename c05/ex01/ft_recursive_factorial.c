/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:51:44 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/24 09:51:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (recursive_factorial(nb));
}

int	recursive_factorial(int nb)
{
	if (nb > 1)
		nb *= recursive_factorial(nb - 1);
	return (nb);
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
	printf("%i\n", ft_recursive_factorial(atoi(argv[1])));
}
*/
