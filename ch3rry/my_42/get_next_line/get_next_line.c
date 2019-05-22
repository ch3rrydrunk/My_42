/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:45:25 by caellis           #+#    #+#             */
/*   Updated: 2019/05/22 19:29:16 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	//DELETE_ME

static t_file	*ft_new_file(const char *content, const int fd)
{
	t_file	*file;
	size_t	size;

	if (content)
		size = ft_strlen(content);
	if ((file = (t_file *)malloc(sizeof(t_file))))
	{
		if (!content)
		{
			file->content = NULL;
			file->size = -1;
		}
		else if ((file->content = ft_strnew(size)))
		{
			ft_memcpy(file->content, content, size);
			file->size = size + 1;
		}
		else
			return (NULL);
		file->fd = fd;
		file->next = NULL;
	}
	return (file);
}

static void		ft_add_file(t_file **files, t_file *new)
{
	t_file	*buff;

	if (files && (!*files) && new)
		*files = new;
	else if (files && *files && new)
	{
		buff = *files;
		*files = new;
		(*files)->next = buff;
	}
}

static t_file	*ft_get_file(t_file **files, int fd)
{
	t_file	*buff;

	buff = *files;
	while (buff)
	{
		if (buff->fd == fd)
			return (buff);
		buff = buff->next;
	}
	buff = ft_new_file("", fd);
	ft_add_file(files, buff);
	return (*files);

}

int				get_next_line(const int fd, char **line)
{
	static t_file	*files;
	t_file			*cue;
	char			*buff;
	char			*temp;
	size_t			rb;

	if (!line || fd < 0 || BUFF_SIZE < 1 || !(cue = ft_get_file(&files, fd)) \
				|| read(fd, buff, 0) < 0 || !(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((rb = read(fd, buff, BUFF_SIZE)))
	{
		if (!(temp = ft_strjoin(cue->content, buff)))
		{
			ft_strdel(&cue->content);
			return (-1);
		}
		if (ft_strchr(cue->content, (int)'\n'))
			break;
	}

	return (1);
}

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;

	ret = -100;
	fd = open("line_less_than_buff.test", O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("That's it?\n");
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}

/*
WIP : get_next_line after error_check
	if ((t_rb = ft_readc_to_lst(&cue, fd, (int)'\n')) < 0)
		return (-1);
	if (!t_rb && !cue->content)
	{
		ft_strclr(cue->content);
		return (0);
	}
	buff = ft_memccpy(*line, cue->content, (int)'\n', t_rb);
	if (buff)
	{
		ft_memdel(&(cue->content));
		cue->content = ft_strdup(buff);
	}
	else
		ft_strdel(cue->content);
	return (1);
	*/