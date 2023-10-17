/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:22:58 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/17 23:23:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] && src_len < size - 1 && size != 0)
	{
		dest[src_len] = src[src_len];
		src_len++;
	}
	dest[src_len] = '\0';
	while (src[src_len])
		src_len++;
	return (src_len);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Input destination and source string, and max total size!\n");
		return (1);
	}

	printf("%i\n", ft_strlcpy(argv[1], argv[2], atoi(argv[3])));
	printf("%s\n", argv[1]);
	while (*argv[1])
	{
		write(1, argv[1], 1);
		argv[1]++;
	}
	write(1, "\n",1);
}
*/
