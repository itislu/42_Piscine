/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:11:36 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/16 23:11:37 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_for_outer_4(char **outer, char ***board, int side);
void	check_for_outer_1(char **outer, char ***board);
void	check_for_outer_3(char **outer, char ***board);
void	check_for_outer_2_opp_1(char **outer, char ***board);
void	check_for_outer_2_or_3(char **outer, char ***board);
void	check_for_outer_3_opp_2(char **outer, char ***board);
void	check_for_4_two_front_of_outer_2(char **outer, char ***board);
void	check_for_3_three_front_of_outer_3_opp_1(char **outer, char ***board);
void	eliminate_from_placed(char ***board, int r, int c, int elim);
void	single_in_row(char ***board, int r, int c, int n);
void	single_in_column(char ***board, int r, int c, int n);
void	zero_rest(char number_leave, char *cell_index);

void	solve_board(char **outer, char ***board)
{
	int	iterations;

	check_for_outer_4(outer, board, 0);
	check_for_outer_1(outer, board);
	check_for_outer_3(outer, board);
	check_for_outer_2_or_3(outer, board);
	check_for_outer_2_opp_1(outer, board);
	check_for_outer_3_opp_2(outer, board);
	iterations = 0;
	while (iterations < 16)
	{
		check_for_4_two_front_of_outer_2(outer, board);
		check_for_3_three_front_of_outer_3_opp_1(outer, board);
		eliminate_from_placed(board, 0, 0, 0);
		single_in_row(board, 0, 0, 0);
		single_in_column(board, 0, 0, 0);
		iterations++;
	}
}

void	check_for_outer_4(char **outer, char ***board, int side)
{
	char	number;
	int		row_col;

	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			number = '1';
			while (outer[side][row_col] == '4' && number <= '4')
			{
				if (side == 0)
					zero_rest(number, board[0 + (number - '0' - 1)][row_col]);
				else if (side == 1)
					zero_rest(number, board[row_col][3 - (number - '0' - 1)]);
				else if (side == 2)
					zero_rest(number, board[3 - (number - '0' - 1)][row_col]);
				else if (side == 3)
					zero_rest(number, board[row_col][0 + (number - '0' - 1)]);
				number++;
			}
			row_col++;
		}
		side++;
	}
}

void	check_for_outer_1(char **outer, char ***board)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			if (outer[side][row_col] == '1')
			{
				if (side == 0)
					zero_rest('4', board[0][row_col]);
				else if (side == 1)
					zero_rest('4', board[row_col][3]);
				else if (side == 2)
					zero_rest('4', board[3][row_col]);
				else if (side == 3)
					zero_rest('4', board[row_col][0]);
			}
			row_col++;
		}
		side++;
	}
}

void	check_for_outer_3(char **outer, char ***board)
{
	int	side;
	int	row_col;

	side = 0;
	while (side < 4)
	{
		row_col = 0;
		while (row_col < 4)
		{
			if (outer[side][row_col] == '3')
			{
				if (side == 0)
					board[0][row_col][2] = '0';
				else if (side == 1)
					board[row_col][3][2] = '0';
				else if (side == 2)
					board[3][row_col][2] = '0';
				else if (side == 3)
					board[row_col][0][2] = '0';
			}
			row_col++;
		}
		side++;
	}
}
