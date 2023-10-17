/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:10:50 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/13 23:10:51 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
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

	printf("%i\n", ft_str_is_alpha(argv[1]));
	return (0);
}
*/
