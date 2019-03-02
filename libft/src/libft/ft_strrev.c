/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:55:21 by tdelabro          #+#    #+#             */
/*   Updated: 2018/11/14 13:26:10 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	if (str)
	{
		len = ft_strlen(str);
		i = 0;
		while (i < len / 2)
		{
			tmp = str[i];
			str[i] = str[len - 1 - i];
			str[len - 1 - i] = tmp;
			i++;
		}
		return (str);
	}
	return (NULL);
}
