/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:50:37 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 09:51:19 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (*dest && len < size)
	{
		len++;
		dest++;
	}
	while (*src && len < size - 1 && size != 0)
	{
		*dest = *src;
		dest++;
		src++;
		len++;
	}
	if (size > 0)
		*dest = '\0';
	while (*src)
	{
		len++;
		src++;
	}
	return (len);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Input destination and source string, and max total size!\n");
		return (1);
	}

	printf("%i\n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
	printf("%s\n", argv[1]);
}
*/
