/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:01:35 by caellis           #+#    #+#             */
/*   Updated: 2019/04/10 18:03:11 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*buff;

	buff = s1;
	while (*buff)
		buff++;
	while (n && *s2)
	{
		*(buff++) = *(s2++);
		n--;
	}
	*buff = '\0';
	return (s1);
}
