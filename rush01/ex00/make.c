/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:12:06 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/16 23:12:07 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	make_outer(char *user_input, char **outer)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			outer[side][row_col] = *user_input;
			if (*(user_input + 1) == '\0')
				return ;
			user_input += 2;
			row_col++;
		}
		if (side == 0)
			side += 2;
		else if (side == 2)
			side++;
		else if (side == 3)
			side -= 2;
		else
			return ;
	}
}

void	make_board(char ***board)
{
	char	number;
	int		r;
	int		c;
	int		n;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			n = 0;
			number = '1';
			while (n < 4)
			{
				board[r][c][n] = number;
				number++;
				n++;
			}
			c++;
		}
		r++;
	}
}
