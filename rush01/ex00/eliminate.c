/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eliminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:11:52 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/16 23:11:54 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	single_in_cell(char *cell)
{
	int		n;
	int		is_single;
	char	single_number;

	n = 0;
	is_single = 0;
	while (n < 4 && is_single <= 1)
	{
		if (cell[n] != '0')
		{
			is_single++;
			single_number = n + 1 + '0';
		}
		n++;
	}
	if (is_single == 1)
		return (single_number);
	else
		return ('5');
}

void	zero_rest(char number_leave, char *cell_index)
{
	char	number;

	number = '1';
	while (number <= '4')
	{
		if (number != number_leave)
			*cell_index = '0';
		cell_index++;
		number++;
	}
}

void	eliminate_from_placed(char ***board, int r, int c, int elim)
{
	int	r_elim;
	int	c_elim;

	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			elim = single_in_cell(board[r][c]) - '0';
			if (elim != 5)
			{
				c_elim = -1;
				while (++c_elim < 4)
					if (c_elim != c)
						board[r][c_elim][elim - 1] = '0';
				r_elim = -1;
				while (++r_elim < 4)
					if (r_elim != r)
						board[r_elim][c][elim - 1] = '0';
			}
			c++;
		}
		r++;
	}
}

void	single_in_row(char ***board, int r, int c, int n)
{
	int	is_single;
	int	single_row;

	while (c < 4)
	{
		n = 0;
		while (n < 4)
		{
			r = 0;
			is_single = 0;
			while (r < 4 && is_single <= 1)
			{
				if (board[r][c][n] != '0')
				{
					is_single++;
					single_row = r;
				}
				r++;
			}
			if (is_single == 1)
				zero_rest(n + 1 + '0', board[single_row][c]);
			n++;
		}
		c++;
	}
}

void	single_in_column(char ***board, int r, int c, int n)
{
	int	is_single;
	int	single_column;

	while (r < 4)
	{
		n = 0;
		while (n < 4)
		{
			c = 0;
			is_single = 0;
			while (c < 4 && is_single <= 1)
			{
				if (board[r][c][n] != '0')
				{
					is_single++;
					single_column = c;
				}
				c++;
			}
			if (is_single == 1)
				zero_rest(n + 1 + '0', board[r][single_column]);
			n++;
		}
		r++;
	}
}
