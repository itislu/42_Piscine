/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:19:55 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/20 23:20:03 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(long nb, long test)
{
	if (nb % test == 0)
		return (0);
	if (test * test <= nb)
		return (is_prime(nb, test + 1));
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (is_prime(nb, 2))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Input one number!\n");
		return (1);
	}

	printf("%i\n", ft_find_next_prime(atoi(argv[1])));
}
*/
