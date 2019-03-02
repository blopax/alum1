/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:19:17 by tdelabro          #+#    #+#             */
/*   Updated: 2018/11/09 21:13:02 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		pos;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			pos = i;
			while (haystack[i + j] == needle[j] \
					&& needle[j] != '\0' && i + j < len)
				j++;
			if (needle[j] == '\0')
				return (&((char*)haystack)[pos]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
