/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:31:09 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/09 18:55:17 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return ;
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input 2 numbers!\n");
		return (1);
	}

	int	a;
	int	b;
	int	div_result;
	int	mod_result;

	a = atoi (argv[1]);
	b = atoi (argv[2]);
	
	ft_div_mod(a, b, &div_result, &mod_result);
	
	if (b != 0)
		printf("a / b = %d\nremainder: %d\n", div_result, mod_result);
}
*/
