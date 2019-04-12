/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:42:41 by caellis           #+#    #+#             */
/*   Updated: 2019/04/11 21:26:54 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		l_dst;  //28
	size_t		l_src;  //19

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size < (l_dst + 1) || size == 0) // 23 < 29
	{
		if (size)
			ft_strncat(dst, src, 0);
		return (l_src + size);
	}
	else
		ft_strncat(dst, src, size - l_dst - 1);
	return (l_dst + l_src);
}
