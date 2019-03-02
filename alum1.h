/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:31 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 15:22:00 by tdelabro         ###   ########.fr       */
>>>>>>> 2511f27225324fcf02f933a87fdcdd2c44ee8df5
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
int		*ft_resolve_turn(int *board, int *winning_strat);

#endif
