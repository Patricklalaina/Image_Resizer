/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:53:09 by fidrandr          #+#    #+#             */
/*   Updated: 2024/10/17 22:06:58 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != c)
	{
		count++;
		str++;
	}
	return (count);
}

char	*gnl_strdup(char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (free(new_str), NULL);
	i = -1;
	while (s[++i])
		new_str[i] = s[i];
	new_str[i] = '\0';
	return (new_str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	if (!s1)
	{
		res = gnl_strdup(s2);
		return (res);
	}
	if (!s2)
		return (NULL);
	k = gnl_strlen(s1, '\0') + gnl_strlen(s2, '\0');
	res = (char *)malloc(sizeof(char) * (k + 1));
	if (!res)
		return (NULL);
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[++j] != '\0')
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

int	get_len(char *stock_fd)
{
	int	len;

	if (check_line(stock_fd))
		len = gnl_strlen(stock_fd, '\n') + 1;
	else
		len = gnl_strlen(stock_fd, '\0');
	return (len);
}
