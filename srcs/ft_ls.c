/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 17:10:42 by alallema          #+#    #+#             */
/*   Updated: 2016/05/26 15:58:05 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int		ft_check_point(char *s)
{
	int				i;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	len--;
	while (s[len] != '/' && s[len] != '.')
		len--;
	while (s[len] != '/' && s[len] == '.')
	{
		i++;
		len--;
	}
	if (i == 1 || i == 2)
	{
		if ((ft_strlen(s)) - 3 <= len)
			return (1);
	}
	return (0);
}

static void		ft_rec_ls(t_lst *lst, char *flag)
{
	struct stat		s;

	if (lst)
	{
		while (lst)
		{
			if (lstat(lst->d_name, &s) != 0)
				return ;
			if (S_ISDIR(s.st_mode) == 1)
			{
				if (ft_check_point(lst->d_name) == 0)
				{
					ft_putchar('\n');
					ft_putstr(lst->d_name);
					ft_putchar(':');
					ft_putchar('\n');
					ft_ls(lst->d_name, flag);
				}
			}
			lst = lst->next;
		}
	}
}

static t_lst	*ft_creat_ls(char *d_name, char *flag, char *o_dir,
t_lst *lst)
{
	if (A == '1')
	{
		if (!lst)
			lst = ft_lstcrea(ft_str_odir(o_dir, d_name), flag);
		else
			ft_sortlst(&lst, ft_str_odir(o_dir, d_name), flag);
	}
	else if (ft_strncmp(d_name, ".", 1) != 0 && ft_strcmp(d_name,
			"..") != 0)
	{
		if (!lst)
			lst = ft_lstcrea(ft_str_odir(o_dir, d_name), flag);
		else
			ft_sortlst(&lst, ft_str_odir(o_dir, d_name), flag);
	}
	return (lst);
}

static int		ft_check_lst(t_lst **lst, char *o_dir, char *flag)
{
	struct stat		s;

	if (L == '1' && lstat(o_dir, &s) == 0 && S_ISLNK(s.st_mode) == 1 &&
		stat(o_dir, &s) == 0)
	{
		*lst = ft_lstcrea(o_dir, flag);
		return (1);
	}
	return (0);
}

t_lst			*ft_ls(char *o_dir, char *flag)
{
	DIR				*dir;
	struct dirent	*entry;
	t_lst			*lst;
	struct stat		s;
	int				err;

	lst = NULL;
	dir = opendir(o_dir);
	err = errno;
	if (((!dir && LSTAT) || (!dir && errno == 13)) && ft_print_err(o_dir))
		return (NULL);
	if (dir && ft_check_lst(&lst, o_dir, flag) == 0)
	{
		while ((entry = readdir(dir)))
			lst = ft_creat_ls(entry->d_name, flag, o_dir, lst);
	}
	if (lstat(o_dir, &s) == 0 && !dir)
		lst = ft_creat_ls(o_dir, flag, "", lst);
	print_lst(lst, flag, err);
	if (R == '1' && err != 20)
		ft_rec_ls(lst, flag);
	if (dir && (closedir(dir) < 0))
		return (NULL);
	return (lst);
}
