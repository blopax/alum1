/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:31 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 15:19:36 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include <fcntl.h>
# include <stdlib.h>

int		*ft_get_board(int fd);
int		*ft_get_strat(int *board);
int		*ft_resolve_turn(int *board, int *winning_strat);

#endif
