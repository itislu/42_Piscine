/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:55:33 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/08 13:25:11 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

char	select_letter(int lst_clmn, int lst_line, int curr_clmn, int curr_line)
{
	char	letter_s;

	if (curr_clmn == 1 && (curr_line == 1 || curr_line == lst_line))
	{
			letter_s = 'A';
	}
	else if (curr_clmn == lst_clmn && (curr_line == 1 || curr_line == lst_line))
	{
			letter_s = 'C';
	}
	else if (curr_line == 1 || curr_line == lst_line)
	{
			letter_s = 'B';
	}
	else if (curr_clmn == 1 || curr_clmn == lst_clmn)
	{
			letter_s = 'B';
	}
	else
	{
			letter_s = ' ';
	}
	return (letter_s);
}

int	rush(int x, int y)
{
	int		curr_line;
	int		curr_clmn;
	char	letter_r;

	if (x < 0 || y < 0)
	{
		return (1);
	}
	curr_line = 0;
	while (++curr_line <= y)
	{
		curr_clmn = 0;
		while (++curr_clmn <= x)
		{	
			letter_r = select_letter(x, y, curr_clmn, curr_line);
			ft_putchar(letter_r);
		}
		if (y >= 0)
		{
			ft_putchar('\n');
		}
	}
	return (0);
}
