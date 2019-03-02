/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:24:59 by pclement          #+#    #+#             */
/*   Updated: 2019/03/02 17:37:23 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	ft_brag(int human_can_win)
{
	if (human_can_win == 0)
		ft_putstr("Only god can save you!\n");
	else if (human_can_win == 1)
		ft_putstr("I may let you win...if you are smart enough!\n");
	else
		ft_putstr("You must have cheated! There is no way you can beat me!\n");
}

void	print_get_strat(int *winning_strat)
{
	int i;

	i = 0;
	while (winning_strat[i] >= 0)
	{
		ft_putstr("On line ");
		ft_putnbr(i);
		if (winning_strat[i] == 0)
			ft_putstr(": Don't take the last match.\n");
		else
			ft_putstr(": Take the last match.\n");
		i++;
	}
}
