/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:31:27 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 17:31:43 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putposnbr(int pos);

void	ft_putnbr(int nb)
{
	if (nb >= 0)
		putposnbr(nb);
	else if (nb == (-2147483648))
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= (-1);
		putposnbr(nb);
	}
}

void	putposnbr(int pos)
{
	char	digit;

	if (pos >= 10)
		putposnbr(pos / 10);
	digit = '0' + (pos % 10);
	write (1, &digit, 1);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input a number into the terminal!\n");
		return (1);
	}
	ft_putnbr(atoi (argv[1]));
}
*/
