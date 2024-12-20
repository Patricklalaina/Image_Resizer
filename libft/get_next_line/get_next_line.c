/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:52:55 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/25 09:40:57 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_file(int fd, char *stock)
{
	int		rdline;
	char	*buf;

	rdline = 1;
	while (rdline != 0 && !check_line(stock))
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		rdline = (int)read(fd, buf, BUFFER_SIZE);
		if (rdline < 0)
			return (free(buf), free(stock), NULL);
		buf[rdline] = '\0';
		stock = gnl_strjoin(stock, buf);
		free(buf);
	}
	return (stock);
}

char	*extract_line(char *stock_fd)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	if (!stock_fd[0])
		return (NULL);
	len = get_len(stock_fd);
	line = (char *) malloc((len + 1) * sizeof(char));
	if (!line)
		return (free(line), NULL);
	while (stock_fd[i] != '\0' && stock_fd[i] != '\n')
	{
		line[i] = stock_fd[i];
		i++;
	}
	if (stock_fd[i] == '\n')
	{
		line[i] = stock_fd[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line_free(char *stock_fd)
{
	char	*next_line;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (stock_fd[i] != '\0' && stock_fd[i] != '\n')
		i++;
	if (!stock_fd[i])
		return (free(stock_fd), NULL);
	len = gnl_strlen(stock_fd + i, '\0');
	next_line = (char *)malloc((len + 1) * sizeof(char));
	if (!next_line)
		return (free(next_line), NULL);
	j = 0;
	i++;
	while (stock_fd[i])
		next_line[j++] = stock_fd[i++];
	next_line[j] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_file(fd, stock);
	if (stock == NULL)
		return (NULL);
	line = extract_line(stock);
	tmp = next_line_free(stock);
	free(stock);
	stock = NULL;
	stock = tmp;
	if (!tmp[0])
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}
