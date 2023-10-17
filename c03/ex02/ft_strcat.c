/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:44:56 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 09:45:21 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*dest_original;

	dest_original = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_original);
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

	printf("%s\n", ft_strcat(argv[1], argv[2]));
}*/
