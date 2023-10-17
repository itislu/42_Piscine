/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:08:34 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/14 10:10:26 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input a string!\n");
		return (1);
	}

	printf("%i\n", ft_str_is_numeric(argv[1]));
	return (0);
}
*/
