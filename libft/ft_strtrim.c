/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:11:21 by alallema          #+#    #+#             */
/*   Updated: 2016/04/22 16:52:06 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	len = ft_strlen((char *)s) - 1;
	if (i <= len)
	{
		while (s[len] && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
			len--;
	}
	str = (char *)malloc(sizeof(char) * ((len - i) + 2));
	if (str == NULL || i == (len + 1))
		return (ft_strdup(""));
	while (i <= len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
