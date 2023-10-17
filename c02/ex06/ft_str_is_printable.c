/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:13:13 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/14 10:13:28 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			return (0);
		str++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	printf("%i\n", ft_str_is_printable(argv[1]));
	return (0);
}
*/
