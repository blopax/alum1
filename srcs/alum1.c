/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:07 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 19:38:11 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	ft_robot_first(int *board, int *winning_strat, char *input)
{
	t_bool	winner;

	while (1)
	{
		ft_putstr("\nMy turn to play\n");
		ft_print_board(board);
		ft_resolve_turn(board, winning_strat);
		winner = FALSE;
		if (board[0] == 0)
			break ;
		ft_putstr("\nYour turn to play.\nPick some matches on the last line\n");
		ft_print_board(board);
		get_next_line(0, &input);
		while (ft_parse_play(board, input) == FALSE)
		{
			ft_memdel((void**)&input);
			get_next_line(0, &input);
		}
		ft_actualise_board(board, ft_atoi(input));
		ft_memdel((void**)&input);
		winner = TRUE;
		if (board[0] == 0)
			break ;
	}
	return (winner);
}

static int	ft_human_first(int *board, int *winning_strat, char *input)
{
	t_bool	winner;

	while (1)
	{
		ft_putstr("\nYour turn to play.\nPick some matches on the last line\n");
		ft_print_board(board);
		get_next_line(0, &input);
		while (ft_parse_play(board, input) == FALSE)
		{
			ft_memdel((void**)&input);
			get_next_line(0, &input);
		}
		ft_actualise_board(board, ft_atoi(input));
		ft_memdel((void**)&input);
		winner = TRUE;
		if (board[0] == 0)
			break ;
		ft_putstr("\nMy turn to play\n");
		ft_print_board(board);
		ft_resolve_turn(board, winning_strat);
		winner = FALSE;
		if (board[0] == 0)
			break ;
	}
	return (winner);
}

static void	ft_victory(int winner, int *board, int *winning_strat)
{
	ft_memdel((void**)&board);
	ft_memdel((void**)&winning_strat);
	if (winner == TRUE)
		write(1, "alum1 won\n", 10);
	else
		write(1, "human won\n",10);
}

int	main(int ac, char **av)
{
	int		fd;
	int		*board;
	char	*input;
	int		*winning_strat;
	int		player_to_start;
	
	if ((fd = ft_get_fd(ac, av)) == -1)
		return (ft_error(1, NULL, -1));
	if ((board = ft_get_board(fd)) == NULL)
		return (ft_error(2, NULL, fd));
	if (!(winning_strat = ft_get_strat(board)))
		return (ft_error(3, board, fd));
	ft_putstr("Do you want to play first or second ?\n");
	get_next_line(0, &input);
	while ((player_to_start = ft_parse_player(input)) == 0)
	{
		ft_memdel((void**)&input);
		get_next_line(0, &input);
	}
	ft_memdel((void**)&input);
	if (player_to_start == 1)
		ft_victory(ft_human_first(board, winning_strat, input), board, winning_strat);
	else
		ft_victory(ft_robot_first(board, winning_strat, input), board, winning_strat);
	return (0);
}
