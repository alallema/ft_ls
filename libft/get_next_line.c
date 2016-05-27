/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:38:42 by alallema          #+#    #+#             */
/*   Updated: 2016/05/01 17:53:42 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_fix_join(char *s, char *buf)
{
	char			*tmp;

	tmp = s;
	s = ft_strjoin(tmp, buf);
	free(tmp);
	return (s);
}

static char			*ft_lstcheck_fd(t_list **alst, char *content, int fd)
{
	t_list			*elem;
	char			*s;
	int				i;
	char			*tmp;

	i = 0;
	elem = *alst;
	while (elem->i != fd && elem->next)
		elem = elem->next;
	if (elem->i != fd)
	{
		elem = ft_lstnew((void *)"", (size_t)1, fd);
		ft_lstadd(alst, elem);
	}
	tmp = ft_fix_join(elem->content, content);
	while (tmp[i] && tmp[i] != C)
		i++;
	s = ft_strsub(tmp, 0, i);
	ft_strcpy(tmp, &tmp[i + 1]);
	elem->content = tmp;
	return (s);
}

static t_list		*ft_lstfind_i(t_list *elem, int fd)
{
	while (elem->i != fd && elem->next)
		elem = elem->next;
	return (elem);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp[2];
	int				ret;
	static t_list	*lst;
	t_list			*elem;

	if (fd < 0 || BUFF_SIZE < 0 || !line || !(tmp[0] = ft_strnew(1)))
		return (-1);
	while ((!ft_strchr(tmp[0], C)) && ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
			&& (buf[ret] = '\0') == '\0')
		tmp[0] = ft_fix_join(tmp[0], buf);
	elem = lst;
	if (lst)
		elem = ft_lstfind_i(lst, fd);
	tmp[1] = elem ? elem->content : "\0";
	if (ret == 0 && tmp[1][0] == '\0' && tmp[0][0] == '\0' && !(*line = NULL))
		return (0);
	if ((!lst && !(lst = ft_lstnew((void *)"", 1, fd))) || ret < 0)
		return (-1);
	if (lst)
		*line = ft_lstcheck_fd(&lst, tmp[0], fd);
	free(tmp[0]);
	return (1);
}
