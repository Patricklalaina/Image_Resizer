/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:55:30 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/15 10:00:31 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*res;

	i = 0;
	res = (void *)s;
	if (c == 0 && n == 0)
		return (NULL);
	while (i < n)
	{
		if (res[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
