/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:53:54 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/24 09:54:18 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_sqrt(int nb, int root, int diff, long square)
{
	if (square < nb)
	{
		root++;
		diff += 2;
		square += diff;
		return (find_sqrt(nb, root, diff, square));
	}
	else if (square == nb)
		return (root);
	else
		return (0);
}

int	ft_sqrt(int nb)
{
	return (find_sqrt(nb, 1, 1, 1));
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

	printf("%i\n", ft_sqrt(atoi(argv[1])));
}
*/
