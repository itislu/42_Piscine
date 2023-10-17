/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:11:42 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/16 23:11:44 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	zero_rest(char number_leave, char *cell_index);
char	single_in_cell(char *cell);

void	check_for_outer_2_or_3(char **outer, char ***board)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			if (outer[side][row_col] == '2' || outer[side][row_col] == '3')
			{
				if (side == 0)
					board[0][row_col][3] = '0';
				else if (side == 1)
					board[row_col][3][3] = '0';
				else if (side == 2)
					board[3][row_col][3] = '0';
				else if (side == 3)
					board[row_col][0][3] = '0';
			}
			row_col++;
		}
		side++;
	}
}

void	check_for_outer_2_opp_1(char **outer, char ***board)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			if (outer[side][row_col] == '2' 
				&& outer[(side + 2) % 4][row_col] == '1')
			{
				if (side == 0)
					zero_rest('3', board[0][row_col]);
				else if (side == 1)
					zero_rest('3', board[row_col][3]);
				else if (side == 2)
					zero_rest('3', board[3][row_col]);
				else if (side == 3)
					zero_rest('3', board[row_col][0]);
			}
			row_col++;
		}
		side++;
	}
}

void	check_for_outer_3_opp_2(char **outer, char ***board)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			if (outer[side][row_col] == '3' 
				&& outer[(side + 2) % 4][row_col] == '2')
			{
				if (side == 0 && single_in_cell(board[2][row_col]) == '4')
					board[0][row_col][0] = '0';
				else if (side == 1 && single_in_cell(board[row_col][1]) == '4')
					board[row_col][3][0] = '0';
				else if (side == 2 && single_in_cell(board[1][row_col]) == '4')
					board[3][row_col][0] = '0';
				else if (side == 3 && single_in_cell(board[row_col][2]) == '4')
					board[row_col][0][0] = '0';
			}
			row_col++;
		}
		side++;
	}
}

void	check_for_4_two_front_of_outer_2(char **outer, char ***board)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			if (outer[side][row_col] == '2')
			{
				if (side == 0 && single_in_cell(board[1][row_col]) < '4')
					board[0][row_col][0] = '0';
				else if (side == 1 && single_in_cell(board[row_col][2]) < '4')
					board[row_col][3][0] = '0';
				else if (side == 2 && single_in_cell(board[2][row_col]) < '4')
					board[3][row_col][0] = '0';
				else if (side == 3 && single_in_cell(board[row_col][1]) < '4')
					board[row_col][0][0] = '0';
			}
			row_col++;
		}
		side++;
	}
}

void	check_for_3_three_front_of_outer_3_opp_1(char **outer, char ***board)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			if (outer[side][row_col] == '3' 
				&& outer[(side + 2) % 4][row_col] == '1')
			{
				if (side == 0 && single_in_cell(board[2][row_col]) == '3')
					board[0][row_col][0] = '0';
				else if (side == 1 && single_in_cell(board[row_col][1]) == '3')
					board[row_col][3][0] = '0';
				else if (side == 2 && single_in_cell(board[1][row_col]) == '3')
					board[3][row_col][0] = '0';
				else if (side == 3 && single_in_cell(board[row_col][2]) == '3')
					board[row_col][0][0] = '0';
			}
			row_col++;
		}
		side++;
	}
}
