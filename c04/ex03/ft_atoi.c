/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:33:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 17:34:00 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	if (sign % 2)
		nbr *= (-1);
	return (nbr);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Make an input into the terminal!\n");
		return (1);
	}
	printf("%i\n", ft_atoi(argv[1]));
}
*/
