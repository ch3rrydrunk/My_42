/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:41:24 by cormund           #+#    #+#             */
/*   Updated: 2019/04/11 18:50:54 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = (void*)0;
	while (*(s) != '\0')
	{
		if (*(s) == (char)c)
			tmp = (char*)s;
		s++;
		if ((char)c == '\0' && *(s) == '\0')
			tmp = (char*)s;
	}
	return (tmp);
}