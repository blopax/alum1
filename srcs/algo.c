/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:56:57 by pclement          #+#    #+#             */
/*   Updated: 2019/03/02 18:18:16 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		*create_winning_strat_table(int *board)
{
	int *winning_strat;
	int len;
	int i;

	len = 0;
	i = 0;
	while (board[len] > 0)
		len++;
	if ((winning_strat = (int *)malloc(sizeof(int) * (len + 1))) == 0)
		return (NULL);
	while (i < len)
	{
		winning_strat[i] = 0;
		i++;
	}
	winning_strat[len] = -1;
	return (winning_strat);
}

int		*ft_get_strat(int *board)
{
	int *winning_strat;
	int i;
	int pick_last_match;
	int condition1;
	int condition2;

	winning_strat = create_winning_strat_table(board);
	if (winning_strat == NULL)
		return (NULL);
	i = 0;
	pick_last_match = 0;
	while (board[i] > 0)
	{
		winning_strat[i] = pick_last_match;
		condition1 = (pick_last_match == 0) && (board[i] % 4 == 1);
		condition2 = (pick_last_match == 1) && (board[i] % 4 == 0);
		if (condition1 || condition2)
			pick_last_match = 1;
		else
			pick_last_match = 0;
		i++;
	}
	return (winning_strat);
}

void	ft_resolve_turn(int *board, int *winning_strat)
{
	int i;
	int pick_line_last_match;
	int modulo_last_line;
	int human_can_win;

	i = 0;
	human_can_win = 0;
	while (board[i] > 0)
		i++;
	i--;
	pick_line_last_match = winning_strat[i];
	modulo_last_line = board[i] % 4;
	if (pick_line_last_match == 0 && modulo_last_line != 1)
		board[i] -= (modulo_last_line + 3) % 4;
	else if (pick_line_last_match == 1 && modulo_last_line != 0)
		board[i] -= modulo_last_line;
	else
	{
		board[i] -= 1;
		human_can_win = 1;
	}
	if (board[0] == 0)
		human_can_win = 2;
	ft_brag(human_can_win);
}
