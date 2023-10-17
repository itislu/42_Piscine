/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:15:37 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/10 12:15:40 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input a string!\n");
		return (1);
	}
	
	printf("number of characters: %i\n", ft_strlen(argv[1]));
	return (0);
}
*/
