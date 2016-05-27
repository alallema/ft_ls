/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:43:03 by alallema          #+#    #+#             */
/*   Updated: 2015/11/27 20:39:32 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*t;
	char	*s;
	size_t	i;

	i = 0;
	t = (void *)malloc(sizeof(*t) * size);
	if (t == NULL)
		return (NULL);
	s = t;
	while (i <= size)
	{
		s[i] = 0;
		i++;
	}
	return (t);
}
