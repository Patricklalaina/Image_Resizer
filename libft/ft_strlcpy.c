/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:20:45 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/15 10:00:59 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	slen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (slen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	i = -1;
	while (src[++i] != '\0')
		;
	return (i);
}
