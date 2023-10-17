/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:43:32 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 09:44:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 == *s2 && *s1 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 || (!*s1 && !*s2))
		return (0);
	return (*s1 - *s2);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Input 2 strings and the number of characters to compare!\n");
		return (1);
	}

	printf("%i\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
}*/
