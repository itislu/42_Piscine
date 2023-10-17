/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:29:46 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/07 23:32:30 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	else if (nb == (-2147483648))
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= (-1);
		ft_putnbr(nb);
		return ;
	}
	digit = '0' + (nb % 10);
	write(1, &digit, 1);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input a number!\n");
		return (1);
	}
	ft_putnbr(atoi (argv[1]));
}
*/
