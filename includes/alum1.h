/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:31 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 16:45:13 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

int		*ft_get_board(int fd);
void	ft_print_board(int *board);
int		*ft_get_strat(int *board);
void	ft_resolve_turn(int *board, int *winning_strat);
void	print_get_strat(int *winning_strat);
void	ft_brag(int human_can_win);

#endif
