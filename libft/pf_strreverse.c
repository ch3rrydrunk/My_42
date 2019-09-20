/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <caellis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:51:16 by bnesoi            #+#    #+#             */
/*   Updated: 2019/09/20 16:34:53 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_strreverse(char *str)
{
	size_t	len;
	size_t	front;
	size_t	rear;
	char	swap;

	if (!str || (len = pf_strlen(str)) < 2)
		return ;
	front = 0;
	rear = len - 1;
	while (front < rear)
	{
		swap = str[front];
		str[front] = str[rear];
		str[rear] = swap;
		rear--;
		front++;
	}
}
