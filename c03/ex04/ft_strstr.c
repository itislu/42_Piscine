/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:46:45 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/18 09:50:10 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!*to_find)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && to_find[j])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
		{
			if (str[i - 1] == to_find[j - 1])
				return (&str[i - j]);
			else
				return (NULL);
		}
		if (str[i] != '\0')
			i++;
	}
	return (NULL);
}
/*
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input a string and what to find!\n");
		return (1);
	}

	printf("%s\n", ft_strstr(argv[1], argv[2]));
}
*/
