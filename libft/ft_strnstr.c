/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:43:24 by coholbur          #+#    #+#             */
/*   Updated: 2024/11/29 13:12:54 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	lenlittle;

	j = 0;
	lenlittle = ft_strlen(little);
	if (little[j] == '\0')
		return ((char *)big);
	while (big[j] && j < len)
	{
		if (big[j] == little[0] && ((j + lenlittle) <= len))
		{
			if (ft_strncmp((big + j), little, lenlittle) == 0)
				return ((char *)(big + j));
		}
		j++;
	}
	return (NULL);
}
