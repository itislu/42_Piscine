/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:39:21 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 09:42:49 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input 2 strings!\n");
		return (1);
	}

	printf("%i\n", ft_strcmp(argv[1], argv[2]));
}
*/
