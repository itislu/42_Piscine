/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:22:36 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/12 15:22:39 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (dest - i);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[100];
	char	*src = "src";
	
	printf("Output of function: %s\n", ft_strcpy(dest, src));
	printf("dest: %s\n", dest);
}
*/
