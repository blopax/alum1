/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:56:57 by pclement          #+#    #+#             */
/*   Updated: 2019/03/02 14:29:59 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	*create_winning_strat_table(int *board)
{
	int *winning_strat;
	int len;
	int i;

	len = 1;
	while (board[i] > 0)
		len++;
	if ((winning_strat = (int *)malloc(sizeof(len))) == 0)
		return (NULL); // clean exit free matches table
	while (i < len)
	{
		winning_strat[i] = 0;
		i++;
	}
	winning_strat[len - 1] = -1;
	return (winning_strat);
}

int	*ft_get_strat(int *board)
{
	int *winning_strat;
	int i;
	int pick_last_match;
	int condition1;
	int condition2;

	winning_strat = create_winning_strat_table(board);
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

int	*ft_resolve_board(int *board)
{
	return (board);
}
