/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:08:54 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/19 09:09:48 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	hex1;
	char	hex2;

	while (*str)
	{
		if (*str > 31 && *str < 127)
			write(1, str, 1);
		else
		{
			hex1 = *str / 16;
			if (hex1 <= 9)
				hex1 += '0';
			else
				hex1 = 'a' + (hex1 - 10);
			hex2 = *str % 16;
			if (hex2 <= 9)
				hex2 += '0';
			else
				hex2 = 'a' + (hex2 - 10);
			write(1, "\\", 1);
			write (1, &hex1, 1);
			write(1, &hex2, 1);
		}
		str++;
	}
}

int	main(void)
{
	ft_putstr_non_printable("test\ntest\e\r");
	write(1, "\n", 1);
}

