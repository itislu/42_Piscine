/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:22:38 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/27 16:23:09 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_duplicate(char *base, int len);

/*Returns length of base if base is valid, otherwise 0*/
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

/*Checks if base has any duplicates*/
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
