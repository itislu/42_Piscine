/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:20:58 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/27 15:21:08 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
int		check_duplicate(char *base, int len);
long	cnvrt_to_decimal(char *nbr, char *base_from, int len_base_from);
char	*cnvrt_to_base(long nbr_dec, char *base_to, int len_base_to, int sign);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		len_base_from;
	int		len_base_to;
	long	nbr_dec;

	while ((*nbr >= 9 && *nbr <= 13) || *nbr == 32)
		nbr++;
	sign = 0;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign = (sign + 1) % 2;
		nbr++;
	}
	len_base_from = check_base(base_from);
	len_base_to = check_base(base_to);
	if (len_base_from == 0 || len_base_to == 0)
		return (NULL);
	nbr_dec = cnvrt_to_decimal(nbr, base_from, len_base_from);
	if ((nbr_dec == 0 && *nbr != *base_from) || 
		(nbr_dec > 2147483647 && sign == 0) || 
		(nbr_dec > 2147483648 && sign == 1))
		return (NULL);
	return (cnvrt_to_base(nbr_dec, base_to, len_base_to, sign));
}

/*Converts string from base_from to decimal int*/
long	cnvrt_to_decimal(char *nbr, char *base_from, int len_base_from)
{
	long	nbr_dec;
	int		s;
	int		b;

	nbr_dec = 0;
	s = 0;
	while (nbr[s])
	{
		b = 0;
		while (nbr[s] != base_from[b] && base_from[b])
			b++;
		if (b == len_base_from)
			return (nbr_dec);
		nbr_dec = nbr_dec * len_base_from + b;
		s++;
	}
	return (nbr_dec);
}

/*Converts nbr_dec from decimal to base_to*/
char	*cnvrt_to_base(long nbr_dec, char *base_to, int len_base_to, int sign)
{
	char	*result;
	int		len_result;
	long	n;

	if (nbr_dec == 0)
		sign = 0;
	len_result = sign;
	n = nbr_dec;
	while (len_result++, n >= len_base_to)
		n /= len_base_to;
	result = (char *) malloc(len_result + 1);
	if (result == NULL)
		return (NULL);
	result[len_result] = '\0';
	while (len_result > sign)
	{
		result[len_result - 1] = base_to[nbr_dec % len_base_to];
		nbr_dec /= len_base_to;
		len_result--;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
/*
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*result;

	if (argc != 4)
	{
		printf("Input into the terminal a number, ");
		printf("a base string the number is in, ");
		printf("and a base string to convert it to!\n");
		return (1);
	}

	result = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s\n", result);
	free(result);
}
*/
