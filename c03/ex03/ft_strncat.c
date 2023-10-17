/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:45:51 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 09:46:23 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest_original;

	dest_original = dest;
	while (*dest)
		dest++;
	while (*src && nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (dest_original);
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

	printf("%s\n", ft_strncat(argv[1], argv[2], atoi(argv[3])));
}*/
