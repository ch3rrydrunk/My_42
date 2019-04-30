/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:44:34 by caellis           #+#    #+#             */
/*   Updated: 2019/04/30 16:27:40 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearray(char ***arr)
{
	if (*arr != NULL)
	{
		while (**arr)
			free(**arr++);
		free(*arr);
	}
}