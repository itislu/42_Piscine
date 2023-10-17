/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:52:49 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/24 09:53:03 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power > 0)
	{
		nb *= ft_recursive_power(nb, power - 1);
		return (nb);
	}
	if (power < 0)
		return (0);
	return (1);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input a number and a power!\n");
		return (1);
	}
	printf("%i\n", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
}
*/
