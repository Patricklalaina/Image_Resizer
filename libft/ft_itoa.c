/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:30:49 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/15 10:00:26 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init(int *n, int i[4], int j)
{
	while (j > 0)
	{
		i[j - 1] = 0;
		j--;
	}
	if (*n == -2147483648)
	{
		i[3] = 1;
		*n = -2147483647;
	}
	if (*n < 0)
	{
		i[1] = 1;
		*n = -(*n);
	}
	i[2] = *n;
	while (*n > 9)
	{
		*n /= 10;
		(i[0])++;
	}
}

static void	cond(int i[4])
{
	if (i[1] == 1)
		i[0]++;
}

char	*ft_itoa(int n)
{
	int		i[4];
	char	*s;

	init(&n, i, 4);
	cond(i);
	s = (char *)malloc(sizeof(char) * (i[0] + 2));
	if (!s)
		return (NULL);
	s[i[0] + 1] = '\0';
	while (i[0] >= 0 && i[2] > 9)
	{
		s[i[0]] = i[2] % 10 + '0' + i[3];
		i[2] /= 10;
		i[3] = 0;
		(i[0])--;
	}
	if (!(i[2] > 9))
		s[i[0]] = i[2] + '0';
	if (i[1] == 1)
		s[i[0] - 1] = '-';
	return (s);
}
