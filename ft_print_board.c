/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:05:49 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 15:04:13 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void ft_write_a_line(int size)
{
	char	str[size];
	int		i;

	i = 0;
	while (i < size)
	{
		str[i] = '|';
		i++;
	}
	write(1, str, size);
}

void	ft_print_board(int *board)
{
	int i;

	i = 0;
	while (board[i] != 0)
	{
		ft_write_a_line(board[i]);
		write(1, "\n", 1);
		i++;
	}
}
