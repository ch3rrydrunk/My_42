/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:44:34 by caellis           #+#    #+#             */
/*   Updated: 2019/05/04 21:15:25 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearray(char ***arr, int max)
{
	if (arr && *arr)
	{
		while (max--)
		{
			if (**arr)
				free(**arr++);
		}
		free(*arr);
	}
}
