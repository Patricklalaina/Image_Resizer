/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:49:13 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/15 10:00:47 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_string(char const *s, char c)
{
	int	count;
	int	i;
	int	new;

	count = 0;
	i = 0;
	new = 1;
	while (s[i] != '\0')
	{
		if (new == 1 && s[i] != c)
		{
			count++;
			new = 0;
		}
		else if (s[i] == c)
			new = 1;
		i++;
	}
	return (count);
}

static int	count_chr(char const *str, char c, int *pos)
{
	int	i;
	int	count;

	i = *pos;
	count = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != '\0' && str[i] != c)
	{
		count++;
		i++;
	}
	while (str[i] == c && str[i] != '\0')
		i++;
	*pos = i;
	return (count);
}

static void	init(int i[4], int j)
{
	while (j > 0)
	{
		i[j - 1] = 0;
		j--;
	}
	i[0] = -1;
}

static void	check(int *i1, int *i2, char const *s, char c)
{
	while (s[*i2] == c)
		(*i2)++;
	*i1 = *i2;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i[4];

	init(i, 4);
	res = (char **)malloc(sizeof(char *) * (count_string(s, c) + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	while ((++i[0]) < count_string(s, c))
	{
		check(&(i[1]), &(i[2]), s, c);
		i[3] = count_chr(s, c, &i[2]);
		res[i[0]] = ft_substr(s, i[1], i[3]);
		if (!res[i[0]])
		{
			while (i[0] >= 0)
				free(res[i[0]--]);
			free(res);
			return (NULL);
		}
	}
	res[i[0]] = NULL;
	return (res);
}
