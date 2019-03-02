/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:34:13 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 21:06:10 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] && s1[i] == s2[i])
			i++;
		return ((((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]));
	}
	return (0);
}
