/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:42:43 by alallema          #+#    #+#             */
/*   Updated: 2016/04/22 17:49:39 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charsplit(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb++;
			i++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	nb++;
	return (nb);
}

static char	**ft_create_tab(char **tab, const char *s, int len, char c)
{
	int		i;
	int		j;

	i = 0;
	while (*s)
	{
		j = 0;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (*s != c && len > 0)
		{
			tab[i][j++] = (char)*s;
			s++;
			len--;
		}
		while (*s == c && len > 0)
		{
			s++;
			len--;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	int		i;
	char	**tab;

	s = ft_strtrimc((char *)s, c);
	len = ft_strlen((char *)s);
	i = ft_charsplit(s, c);
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (tab == NULL || !s | !c || !len)
		return (NULL);
	tab = ft_create_tab(tab, s, len, c);
	return (tab);
}
