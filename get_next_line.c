/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:21:57 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/07/21 21:09:30 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buf;
	char			*line;
	ssize_t			ret;
	ssize_t			i;

	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = 1;
	while (ret > 0 || *stash != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		stash = ft_strjoin(stash, buf);
		if (ret == 0 && *stash == '\0')
			return (free(buf), free(stash), NULL);
		while (stash[i] && stash[i] != '\n')
			i++;
		if (stash[i] == '\n' || (stash[i] == '\0' && ret == 0))
		{
			line = malloc(sizeof(char) * (i + 2));
			ft_strlcpy(line, stash, i + 1);
			if (stash[i] == '\n')
				line[i++] = '\n';
			line[i] = '\0';
			stash = ft_substr(stash, (unsigned int)i, ft_strlen(stash) - i);
			return (free(buf), line);
		}
	}
	return (NULL);
}
