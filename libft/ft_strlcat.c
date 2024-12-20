/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:40:46 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/15 10:00:58 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dst = len(dst);
	len_src = len((char *)src);
	if (size <= len_dst)
		return (len_src + size);
	while (i < (size - len_dst - 1) && src[i] != '\0')
	{
		dst[len_dst + i] = ((char *)src)[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
