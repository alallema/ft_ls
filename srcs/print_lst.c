/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 14:56:21 by alallema          #+#    #+#             */
/*   Updated: 2016/05/26 16:26:28 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				ft_print_err(char *o_dir)
{
	ft_putstr("ls: ");
	if (o_dir[0] == '\0')
		ft_putstr("fts_open: ");
	else
	{
		ft_putstr(o_dir);
		ft_putstr(": ");
	}
	perror("");
	return (1);
}

static void		print_blocks(t_lst *lst, int err)
{
	struct stat		s;
	t_lst			*elem;
	unsigned long	blk;

	elem = lst;
	blk = 0;
	while (elem)
	{
		if (lstat(elem->d_name, &s))
			return ;
		blk = blk + (s.st_blocks);
		elem = elem->next;
	}
	if (!s.st_mode || S_ISLNK(s.st_mode) == 1 || err == 20)
		return ;
	ft_putstr("total ");
	ft_putnbr(blk);
	ft_putchar('\n');
}

static void		print_link(t_lst *elem)
{
	struct stat		s;
	char			*buf;

	buf = (char *)malloc(sizeof(char) * 1024);
	if (lstat(elem->d_name, &s) != 0)
		return ;
	if (S_ISLNK(s.st_mode))
	{
		readlink(elem->d_name, buf, 1024);
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

static int		print_error(t_lst *elem, char *flag, int err)
{
	int				error;

	error = 0;
	if (!err || err == 20 || err == 13 || err == 2)
		error = print_type(elem, flag);
	if (error || (err && err != 20 && err != 13 && err == 2))
		ft_putstr("ls:");
	ft_putchar(' ');
	if (err && err != 20 && err != 13 && err == 2)
		return (err);
	return (error);
}

void			print_lst(t_lst *lst, char *flag, int err)
{
	t_lst			*elem;
	int				error;

	elem = lst;
	error = 0;
	if (L == '1' && !err)
		print_blocks(lst, err);
	while (elem)
	{
		if (elem->d_name)
		{
			if (L == '1')
				error = print_error(elem, flag, err);
			ft_putstr(ft_clean_name(elem->d_name, err));
			if (error || (err && err != 20 && err != 13 && err != 2))
			{
				ft_putchar(' ');
				ft_putstr(strerror(error ? error : err));
			}
			if (L == '1' && !error && !err)
				print_link(elem);
			ft_putchar('\n');
		}
		elem = elem->next;
	}
}
