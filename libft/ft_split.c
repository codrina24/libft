/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:50:00 by coholbur          #+#    #+#             */
/*   Updated: 2024/12/03 16:48:05 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	trigger;
	size_t	cpt;

	i = 0;
	trigger = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] != c && trigger == 0)
		{
			trigger = 1;
			cpt++;
		}
		else if (str[i] == c)
			trigger = 0;
		i++;
	}
	return (cpt);
}

char	*lenmot(char const *s, char c)
{
	size_t	len;
	size_t	len1;
	char	*lavirgule;
	size_t	len2;

	len = 0;
	len1 = 0;
	lavirgule = ft_strchr(s, c);
	if (lavirgule)
		len1 = ft_strlen(lavirgule);
	len2 = ft_strlen(s);
	len = len2 - len1;
	return (ft_substr(s, 0, len));
}

void	free_tab(char **tab, int n)
{
	while (n > 0)
	{
		n--;
		free(tab[n]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	n;

	tab = (char **)malloc(sizeof(char *) * ((count_words(s, c)) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i] && n < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		tab[n] = lenmot(&s[i], c);
		if (!tab[n])
		{
			free_tab(tab, n);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			i++;
		n++;
	}
	tab[n] = NULL;
	return (tab);
}
