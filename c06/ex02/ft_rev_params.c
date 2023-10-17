/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:32:25 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/26 09:32:55 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	a;
	int	c;

	a = argc - 1;
	while (a > 0)
	{
		c = 0;
		while (argv[a][c])
		{
			write(1, &argv[a][c], 1);
			c++;
		}
		write(1, "\n", 1);
		a--;
	}
}