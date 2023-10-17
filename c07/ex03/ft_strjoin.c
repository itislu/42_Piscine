/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:18:10 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/25 20:18:28 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_strs_len(int size, char **strs);
void	concatenate_strs(char *conc_str, int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*conc_str;
	int		strs_len;
	int		sep_len;

	strs_len = count_strs_len(size, strs);
	if (size == 0)
	{
		conc_str = (char *) malloc(1);
		if (conc_str == NULL)
			return (NULL);
		conc_str[0] = '\0';
		return (conc_str);
	}
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	conc_str = (char *) malloc(strs_len + sep_len * (size - 1) + 1);
	if (conc_str == NULL)
		return (NULL);
	concatenate_strs(conc_str, size, strs, sep);
	return (conc_str);
}

int	count_strs_len(int size, char **strs)
{
	int	strs_len;
	int	n;
	int	i;

	strs_len = 0;
	n = 0;
	while (n < size)
	{
		i = 0;
		while (strs[n][i])
		{
			strs_len++;
			i++;
		}
		n++;
	}
	return (strs_len);
}

void	concatenate_strs(char *conc_str, int size, char **strs, char *sep)
{
	int	n;
	int	c;
	int	i;
	int	j;

	n = 0;
	c = 0;
	while (n < size)
	{
		i = -1;
		while (strs[n][++i])
		{
			conc_str[c++] = strs[n][i];
		}
		if (++n < size)
		{
			j = -1;
			while (sep[++j])
			{
				conc_str[c++] = sep[j];
			}
		}
	}
	conc_str[c] = '\0';
}
/*
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Input with the program some strings and ");
		printf("a separator you want to concatenate them with!\n");
		return (1);
	}
	printf("%s\n", ft_strjoin((argc - 2), &argv[1], argv[argc - 1]));
}
*/
