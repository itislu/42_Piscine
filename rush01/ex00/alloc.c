/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:11:23 by ldulling          #+#    #+#             */
/*   Updated: 2023/07/16 23:11:29 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**alloc_outer(char **outer)
{
	int	i;

	outer = (char **) malloc(4 * 8);
	if (outer != NULL)
	{
		i = 0;
		while (i < 4)
		{
			outer[i] = (char *) malloc(4 * 1);
			i++;
		}
	}
	return (outer);
}

char	***alloc_board(char ***board)
{
	int	i;
	int	j;

	board = (char ***) malloc(8 * 4);
	if (board != NULL)
	{
		i = 0;
		while (i < 4)
		{
			board[i] = (char **) malloc(8 * 4);
			if (board[i] != NULL)
			{
				j = 0;
				while (j < 4)
				{
					board[i][j] = (char *) malloc(1 * 4);
					j++;
				}
			}
			i++;
		}
	}
	return (board);
}

void	free_outer(char **outer)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(outer[i]);
		i++;
	}
	free(outer);
}

void	free_board(char ***board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			free(board[i][j]);
			j++;
		}
		free(board[i]);
		i++;
	}
	free(board);
}
