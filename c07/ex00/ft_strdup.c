/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:41:50 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/26 09:43:30 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = 1;
	while (src[len])
		len++;
	dup = (char *) malloc(len);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Input a string!\n");
		return (1);
	}

	char *test = ft_strdup(argv[1]);
	printf("%s\n", test);
	free(test);
}
*/
