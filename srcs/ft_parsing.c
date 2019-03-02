/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:19:35 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 18:30:28 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	ft_get_fd(int ac, char **av)
{
	if (ac > 2)
		return (-1);
	else if (ac == 1)
		return (0);
	else
		return (open(av[1], O_RDONLY));
}

t_bool	ft_parse_play(int *board, char *s)
{
	int i;

	if (ft_strlen(s) != 1 || (s[0] != '1' && s[0] != '2' && s[0] != '3'))
	{
		ft_putstr("You can only pick 1, 2 or 3 of them at once.\n");
		return (FALSE);
	}
	i = 0;
	while (board[i] != 0)
		i++;
	if (s[0] - '0' > board[--i])
	{
		ft_putstr("Not that much !!\n");
		return (FALSE);
	}
	return (TRUE);
}

int	ft_error(int code, int *board, int fd)
{
	if (code == 1)
		write(1, "ERROR: too many arguments\n", 26);
	if (code == 2)
	{
		write(1, "ERROR\n", 6);
		if (fd != 0)
			close(fd);
	}
	if (code == 3)
	{
		write(1, "ERROR: alumn1 faced a unexpected error and quit\n", 45);
		ft_memdel((void**)&board);
		if (fd != 0)
			close(fd);
	}
	return (-1);
}

int	ft_parse_player(char *str)
{
	if (ft_strlen(str) != 1 || (str[0] != '1' && str[0] != '2'))
	{
		ft_putstr("Please enter a correct value: [1/2]\n");
		return (FALSE);
	}
	return (ft_atoi(str));
}
