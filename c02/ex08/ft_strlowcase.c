/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:17:52 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/14 10:18:08 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
		i++;
	}
	return (str - i);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input a string!\n");
		return (1);
	}

	printf("%s\n", ft_strlowcase(argv[1]));
	return (0);
}
*/
