/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 12:47:57 by alallema          #+#    #+#             */
/*   Updated: 2016/05/25 19:47:18 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			*ft_str_odir(char *o_dir, char *d_name)
{
	int			i;
	int			j;
	int			len;
	char		*s;

	len = ft_strlen(o_dir) + ft_strlen(d_name) + 1;
	i = 0;
	j = 0;
	s = (char *)malloc(sizeof(char) * (len + 1));
	while (o_dir && o_dir[i])
	{
		s[i] = o_dir[i];
		i++;
	}
	if (o_dir[0] != '\0')
	{
		s[i] = '/';
		i++;
	}
	while (d_name && d_name[j])
		s[i++] = d_name[j++];
	s[i] = '\0';
	return (s);
}

t_lst			*ft_lstcrea(char *d_name, char *flag)
{
	t_lst		*elem;
	struct stat	s;

	elem = (t_lst *)malloc(sizeof(t_lst));
	if (elem)
	{
		elem->d_name = d_name;
		elem->stat = (t_stat *)malloc(sizeof(t_stat));
		if (T == '1' || L == '1')
		{
			stat(elem->d_name, &s);
			T_SEC = s.st_mtimespec.tv_sec;
			T_NSEC = s.st_mtimespec.tv_nsec;
		}
		elem->next = NULL;
	}
	return (elem);
}
