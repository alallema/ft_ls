/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_post.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:34:19 by alallema          #+#    #+#             */
/*   Updated: 2016/05/01 17:35:49 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr_post(const char *s, int c)
{
	while (*s != (const char)c && *s)
		s++;
	if (*s == (char)c && *s)
	{
		s++;
		return ((char *)s);
	}
	return (NULL);
}
