/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:31 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 14:57:16 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

int		*ft_get_board(int fd);
void	ft_print_board(int *board);

#endif
