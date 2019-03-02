/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:07 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 14:22:43 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	ft_get_fd(int ac, char **av)
{
	if (ac > 2)
		return (-1);
	else if (ac == 1)
		return (0);
	else
		return (open(av[1], O_RDONLY));
}

static t_bool	ft_parse_play(char *str)
{
	if (ft_strlen(str) != 2)
		return (FALSE);
	if (str[0] != '1' || str[0] != '2' || str[0] != '3')
		return (FALSE);
	return (TRUE);
}

static void ft_actualise_board(int *board, int play)
{
	int i;

	i = 0;
	while (board[i] != 0)
		i++;
	board[--i] -= play;
}

int	main(int ac, char **av)
{
	int		fd;
	int		*board;
	char	*play;
	t_bool	winner;
	int		*winning_strat;
	
	if ((fd = ft_get_fd(ac, av)) == -1)
	{
		write(1, "ERROR\n", 6);
		return (-1);
	}
	if ((board = ft_get_board(fd)) == NULL)
	{
		write(1, "ERROR\n", 6);
		if (fd != 0)
			close(fd);
		return (-1);
	}
	winning_strat = ft_get_strat(board);
	play = NULL;
	bord = NULL;
	while (1)
	{
		ft_print_board(board);
		while (ft_parse_play(play) == FALSE)
			get_next_line(0, &play);
		ft_actualise_board(board, ft_atoi(play));
		ft_memdel((void**)&play);
		winner = TRUE;
		if (board[0] == 0)
			break ;
		ft_print_board(board);
		ft_resolve_turn(board, winning_strat);
		winner = FALSE;
		if (board[0] == 0)
			break ;
	}
	ft_memdel((void**)&board);
	if (winner = TRUE)
		write(1, "alum1 won\n", 10);
	else
		write(1, "human won\n",10);
	return (1);
}
