/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:13:56 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/14 10:14:12 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
		i++;
	}
	return (str - i);
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

	printf("%s\n", ft_strupcase(argv[1]));
	return (0);
}
*/
