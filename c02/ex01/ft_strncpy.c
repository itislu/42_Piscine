/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:11:40 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/12 16:11:46 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (dest - i);
}
/*
#include <stdio.h>

int	main(void)
{
	char		dest[100];
	char		*src = "src";
	unsigned int	n = 5;
	
	printf("Output of function: %s\n", ft_strncpy(dest, src, n));
	printf("dest: %s\n", dest);
}
*/
