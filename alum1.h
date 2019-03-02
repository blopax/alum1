/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:31 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 17:45:13 by tdelabro         ###   ########.fr       */
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
void	print_get_strat(int * x);
int		ft_get_fd(int ac, char **av);
t_bool	ft_parse_play(int *board, char *s);
int		ft_parse_player(char *str);
int		ft_error(int code, int *board, int fd);
void	ft_actualise_board(int *board, int play);

#endif
