/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:36:05 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/24 08:36:09 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_duplicate(char *base, int len);
void	print(long nbr, int len, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_l;
	int		len;

	len = 0;
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-')
			return ;
		len++;
	}
	if (len < 2 || check_duplicate(base, len))
		return ;
	nbr_l = nbr;
	if (nbr_l < 0)
	{
		write (1, "-", 1);
		nbr_l *= (-1);
	}
	print(nbr_l, len, base);
}

int	check_duplicate(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print(long nbr, int len, char *base)
{
	if (nbr >= len)
		print(nbr / len, len, base);
	nbr %= len;
	write(1, &base[nbr], 1);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input into the terminal a number and a base system!\n");
		return (1);
	}

	ft_putnbr_base(atoi(argv[1]), argv[2]);
	printf("\n");
}
*/

/*	RECURSION CAUSES TIMEOUT ERROR
int		check_duplicate(char *base, int i, int j, int len)
{
	if (base[i] == base[i + j])
		return (1);
	if (i + j < len - 1)
		if (check_duplicate(base, i, j + 1, len))
			return (1);
	if (i < len - 1)
		if (check_duplicate(base, i + 1, 1, len))
			return (1);
	return (0);
}
*/
