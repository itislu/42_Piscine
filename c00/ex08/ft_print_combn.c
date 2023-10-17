/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:29:57 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/13 16:04:19 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_array(char *array, int n);
void	carry(char *array, int n);

void	ft_print_combn(int n)
{
	char	array[10];
	int		start_pos;
	char	max_number;

	start_pos = 10 - n;
	max_number = '9' - n + 1;
	fill_array(&array[start_pos - 1], n);
	while (array[start_pos] <= max_number)
	{
		while (array[9] <= '9')
		{
			write(1, &array[start_pos], n);
			if (array[start_pos] <= max_number - 1)
				write(1, ", ", 2);
			array[9]++;
		}
		if (n > 1)
			carry(&array[0], n);
	}
}

void	fill_array(char *array, int n)
{
	int	i;

	i = 0;
	*array = '0';
	array++;
	while (i < n)
	{
		*array = '0' + i;
		array++;
		i++;
	}
}

void	carry(char *array, int n)
{
	int		position;
	char	max_digit;

	position = 10 - n;
	max_digit = '0' + position + 1;
	while (array[position] < max_digit)
	{
		position++;
		max_digit++;
	}
	array[position - 1]++;
	while (position <= 9)
	{
		array[position] = array[position - 1] + 1;
		position++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	input;

	if (argc != 2)
	{
		printf("Input a number between 1 and 9!\n");
		return (1);
	}
	input = atoi (argv[1]);
	if (input < 1 || input > 9)
	{
		printf("Input a number between 1 and 9!\n");
		return (1);
	}
	ft_print_combn(input);
	return (0);
}
*/
