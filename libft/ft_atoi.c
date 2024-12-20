/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <fidrandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:52:24 by fidrandr          #+#    #+#             */
/*   Updated: 2024/11/15 09:59:26 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	t_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	cneg;
	int	i;
	int	tmp;

	i = 0;
	cneg = 0;
	tmp = 0;
	while ((nptr[i] == ' ' || nptr[i] == '\v' || nptr[i] == '\f'
			|| nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == '\n')
		&& nptr[i] != '\0')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			cneg++;
		i++;
	}
	while (t_isdigit((int)nptr[i]))
	{
		tmp = tmp * 10 + (nptr[i] - 48);
		i++;
	}
	if (cneg == 1)
		return (-tmp);
	return (tmp);
}
