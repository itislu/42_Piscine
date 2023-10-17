/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:29:46 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/09 11:41:05 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int number);

void	ft_print_comb2(void)
{
	int	number1;
	int	number2;

	number1 = 0;
	while (number1 <= 98)
	{
		number2 = number1 + 1;
		while (number2 <= 99)
		{
			print_number(number1);
			write(1, " ", 1);
			print_number(number2);
			if (number1 == 98)
				return ;
			write(1, ", ", 2);
			number2++;
		}
		number1++;
	}
}

void	print_number(int number)
{
	char	digit[2];

	digit[0] = '0' + number / 10;
	digit[1] = '0' + number % 10;
	write(1, &digit[0], 2);
}
/*
int main(void)
{
	ft_print_comb2();
}
*/
