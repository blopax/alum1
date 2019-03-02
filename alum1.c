/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:38:07 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 11:50:22 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	int fd;
	int	*board;
	int	play;

	if (ac > 2)
	{
		write(1, "ERROR: invalid number of arguments\n", 35);
		return (-1);
	}
	else if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	board = ft_init_board(fd);
	while (board[0] != 0)
	{
		play = ft_atoi(get_	
	}
}
