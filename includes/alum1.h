/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:31 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/03 21:28:04 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include <fcntl.h>
# include "../libft/libft.h"

typedef enum
{
	FALSE,
	TRUE
}	t_bool;

int		*ft_get_board(int fd);
void	ft_print_board(int *board);
int		*ft_get_strat(int *board);
void	ft_resolve_turn(int *board, int *winning_strat);
int		ft_get_fd(int ac, char **av);
t_bool	ft_parse_play(int *board, char *s);
int		ft_parse_player(char *str);
int		ft_error(int code, int *board, int fd);
void	ft_actualise_board(int *board, int play);
void	print_get_strat(int *winning_strat);
void	ft_brag(int human_can_win);

#endif
