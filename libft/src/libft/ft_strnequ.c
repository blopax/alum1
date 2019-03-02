/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:27:51 by tdelabro          #+#    #+#             */
/*   Updated: 2018/11/10 14:30:57 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2 && ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
