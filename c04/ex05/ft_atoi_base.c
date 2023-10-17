/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:28:55 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/24 23:29:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base);
int	check_duplicate(char *base, int len);
int	convert_to_decimal(char *str, char *base, int base_len);

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nbr_dec;
	int	base_len;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	nbr_dec = convert_to_decimal(str, base, base_len);
	if (nbr_dec == 0)
		return (0);
	if (sign % 2)
		nbr_dec *= (-1);
	return (nbr_dec);
}

/* Count base_len and check base validity */
int	check_base(char *base)
{
	int	len;

	len = 0;
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-'
			|| (base[len] >= 9 && base[len] <= 13) || base[len] == ' ')
			return (0);
		len++;
	}
	if (len < 2 || check_duplicate(base, len))
		return (0);
	return (len);
}

int	check_duplicate(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	convert_to_decimal(char *str, char *base, int base_len)
{
	int	nbr_dec;
	int	s;
	int	b;

	nbr_dec = 0;
	s = 0;
	while (str[s])
	{
		b = 0;
		while (str[s] != base[b] && base[b])
			b++;
		if (b == base_len)
			return (nbr_dec);
		nbr_dec = nbr_dec * base_len + b;
		s++;
	}
	return (nbr_dec);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Input into the terminal 
				a number and a base system the number is in!\n");
		return (1);
	}

	printf("%i\n", ft_atoi_base(argv[1], argv[2]));
}
*/
