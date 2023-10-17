/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:38:18 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/27 23:38:46 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_substrs(char *str, char *charset);
char	**split(char *str, char *charset, int substr_count, char **str_array);
int		is_in_charset(char c, char *charset);
void	copy_substr(char **str_array, char **str, int *i, int *j);

char	**ft_split(char *str, char *charset)
{
	char	**str_array;
	int		substr_count;
	int		n;
	int		i;
	int		j;

	substr_count = count_substrs(str, charset);
	str_array = (char **) malloc((substr_count + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	str_array = split(str, charset, substr_count, str_array);
	return (str_array);
}

/*Count how many substrings there will be (for mallocing the pointers)*/
int	count_substrs(char *str, char *charset)
{
	int	substr_count;
	int	i;

	substr_count = 0;
	i = 0;
	while (str[i])
	{
		while (is_in_charset(str[i], charset) && str[i])
			i++;
		if (str[i] && !is_in_charset(str[i], charset))
		{
			substr_count++;
			while (str[i] && !is_in_charset(str[i], charset))
				i++;
		}
	}
	return (substr_count);
}

char	**split(char *str, char *charset, int substr_count, char **str_array)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	while (str[i] && n < substr_count)
	{
		while (is_in_charset(str[i], charset))
			i++;
		j = i;
		while (!is_in_charset(str[j], charset) && str[j])
			j++;
		str_array[n] = (char *) malloc(j - i + 1);
		if (str_array[n] == NULL)
		{
			while (n-- > 0)
				free(str_array[n]);
			free (str_array);
			return (NULL);
		}
		copy_substr(&(str_array[n++]), &str, &i, &j);
	}
	str_array[n] = NULL;
	return (str_array);
}

/*Checks if a character appears in the charset*/
int	is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

/*Copy substr into str_array and null terminate*/
void	copy_substr(char **str_array, char **str, int *i, int *j)
{
	int	s;

	s = 0;
	while (*i < *j)
	{
		(*str_array)[s] = (*str)[*i];
		s++;
		(*i)++;
	}
	(*str_array)[s] = '\0';
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Input with the program a string and the separator(s)!\n");
		return (1);
	}

	char	**str_array;
	int		i;

	str_array = ft_split(argv[1], argv[2]);

	i = 0;
	while (str_array[i] != NULL)
	{
		printf("%s\n", str_array[i]);
		i++;
	}
	return (0);
}

