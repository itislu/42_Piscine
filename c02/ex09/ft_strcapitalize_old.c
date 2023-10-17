/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:49:36 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/14 10:49:42 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c);
int	is_lowercase(char c);
int	is_uppercase(char c);
int	is_number(char c);

char	*ft_strcapitalize(char *str)
{
	char	*str_orig;

	str_orig = str;
	while (*str)
	{
		if (is_lowercase(*str))
			*str -= 'a' - 'A';
		str++;
		while (is_alphanumeric(*str))
		{
			if (is_uppercase(*str))
				*str += 'a' - 'A';
			str++;
		}
		while (!is_alphanumeric(*str) && *str != '\0')
		{
			str++;
		}
	}
	return (str_orig);
}

int	is_alphanumeric(char c)
{
	if (is_lowercase(c) || is_uppercase(c) || is_number(c))
		return (1);
	return (0);
}

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	test_str[] = 
	"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(argv[1]));
}
*/
