/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:51:15 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/15 10:01:15 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	k = -1;
	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	while (check_set(s1[i - 1], set) == 1)
		i--;
	j = 0;
	while (check_set(s1[j], set) == 1)
		j++;
	if (i <= j)
		j = i;
	res = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!res)
		return (NULL);
	while (++k < (i - j) && j < i)
		res[k] = ((char *)s1)[j + k];
	res[k] = '\0';
	return (res);
}
