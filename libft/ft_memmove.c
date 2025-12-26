/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:29:16 by coholbur          #+#    #+#             */
/*   Updated: 2024/11/29 12:30:23 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char				temp;
	char				*a;
	const char			*b;
	size_t				i;

	i = 0;
	a = dest;
	b = src;
	if (a == NULL && b == NULL)
		return (NULL);
	while (a < b && i < n)
	{
		temp = b[i];
		a[i] = temp;
		i++;
	}
	while (a > b && n > 0)
	{
		n--;
		temp = b[n];
		a[n] = temp;
	}			
	return (dest);
}
