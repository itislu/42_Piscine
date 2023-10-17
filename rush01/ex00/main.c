/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:12:00 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/16 23:12:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_input(int argc, char *argv[]);
int		invalid_input(char *user_input);
void	solve_board(char **outer, char ***board);
int		solved_board(char ***board);
int		print_board(char ***board);
char	**alloc_outer(char **outer);
char	***alloc_board(char ***board);
void	free_outer(char **outer);
void	free_board(char ***board);
void	make_outer(char *user_input, char **outer);
void	make_board(char ***board);
char	single_in_cell(char *cell);

int	main(int argc, char *argv[])
{
	char	**outer;
	char	***board;

	if (check_input(argc, argv))
		return (1);
	outer = NULL;
	board = NULL;
	outer = alloc_outer(outer);
	board = alloc_board(board);
	make_outer(argv[1], outer);
	make_board(board);
	solve_board(outer, board);
	if (solved_board(board))
	{
		print_board(board);
		free_board(board);
		free_outer(outer);
		return (0);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}

int	check_input(int argc, char *argv[])
{
	if (argc != 2 || invalid_input(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}

int	invalid_input(char *user_input)
{
	int	counter;

	counter = 0;
	while (*user_input && counter < 32)
	{
		if (counter % 2 == 0 && (*user_input < '1' || *user_input > '4'))
			return (1);
		else if (counter % 2 == 1 && *user_input != ' ')
			return (1);
		user_input++;
		counter++;
	}
	if (counter != 31)
		return (1);
	return (0);
}

int	solved_board(char ***board)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (single_in_cell(board[r][c]) == '5')
			{
				return (0);
			}
			c++;
		}
		r++;
	}
	return (1);
}

int	print_board(char ***board)
{
	char	number;
	int		r;
	int		c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			number = single_in_cell(board[r][c]);
			write(1, &number, 1);
			if (c < 3)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			c++;
		}
		r++;
	}
	return (0);
}
