/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:54:26 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/03 21:23:36 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int		*ft_resize_board(int *board, int *size)
{
	int	*tmp;
	int i;

	*size *= 2;
	if (!(tmp = ft_memalloc(sizeof(int) * (*size + 1))))
		return (NULL);
	i = -1;
	while (board[++i] != 0)
		tmp[i] = board[i];
	ft_memdel((void**)&board);
	return (tmp);
}

static t_bool	ft_parse_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (FALSE);
		i++;
	}
	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (FALSE);
	if (ft_atoi(str) > 10000)
		return (FALSE);
	return (TRUE);
}

static  int     *ft_return(int *board)
{
	if (board[0] != 0)
		return (board);
	else
	{
		ft_memdel((void**)&board);
		return (NULL);
	}
}

int             *ft_get_board(int fd)
{
	int     *board;
	char    *line;
	int     size;
	int     i;

	size = 1;
	if (!(board = ft_memalloc(sizeof(int) * (size + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (fd == 0 && *line == '\0')
			break ;
		if (ft_parse_line(line) == FALSE)
		{
			ft_memdel((void**)&board);
			ft_memdel((void**)&line);
			return (NULL);
		}
		board = (i == size) ? ft_resize_board(board, &size) : board;
		board[i++] = ft_atoi(line);
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	return (ft_return(board));
}

void			ft_actualise_board(int *board, int play)
{
	int i;

	i = 0;
	while (board[i] != 0)
		i++;
	board[--i] -= play;
}
