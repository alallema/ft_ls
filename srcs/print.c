/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:16:30 by alallema          #+#    #+#             */
/*   Updated: 2016/05/26 15:02:17 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void	print_date(t_lst *elem)
{
	char			**date;

	date = ft_strsplit(ctime(&T_SEC), ' ');
	ft_putstr(date[1]);
	ft_putchar(' ');
	if (!date[2][1])
		ft_putchar(' ');
	ft_putstr(date[2]);
	ft_putchar(' ');
	date[3][5] = '\0';
	date[4][4] = '\0';
	if (time(0) - 15552000 >= T_SEC)
	{
		ft_putchar(' ');
		ft_putstr(date[4]);
	}
	else
		ft_putstr(date[3]);
	free(date);
}

static void	print_group(struct stat *s, char *flag)
{
	struct group	*g;
	int				i;

	i = 0;
	g = getgrgid(s->st_gid);
	if (g && N == '0' && O == '0' && g->gr_name)
		ft_putstr(g->gr_name);
	else if (g && O == '0')
		ft_putnbr(s->st_gid);
	ft_putchar(' ');
	if (S_ISBLK(s->st_mode) || S_ISCHR(s->st_mode))
	{
		ft_putchar(' ');
		ft_putnbr(major(s->st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(s->st_rdev));
	}
	else
	{
		while (i++ + ft_strlen(ft_itoa(s->st_size)) < 5)
			ft_putchar(' ');
		ft_putnbr(s->st_size);
	}
	ft_putchar(' ');
}

static int	print_ui(t_lst *elem, char *flag)
{
	struct stat		*s;
	struct passwd	*p;
	int				i;

	i = 0;
	s = (struct stat *)malloc(sizeof(struct stat));
	ft_putchar(' ');
	if (lstat(elem->d_name, s) != 0)
		return (errno);
	if (s->st_nlink < 10)
		ft_putchar(' ');
	ft_putnbr(s->st_nlink);
	ft_putchar(' ');
	p = getpwuid(s->st_uid);
	if (p && N == '0' && G == '0' && p->pw_name)
		ft_putstr(p->pw_name);
	else if (p && G == '0')
		ft_putnbr(s->st_uid);
	ft_putstr("  ");
	print_group(s, flag);
	print_date(elem);
	free(s);
	return (0);
}

static void	print_right(int mode)
{
	char			*tab;

	if (!(tab = malloc(sizeof(char) * 10)))
		return ;
	tab[0] = ((mode & S_IRUSR) != 0) ? 'r' : '-';
	tab[1] = ((mode & S_IWUSR) != 0) ? 'w' : '-';
	tab[2] = ((mode & S_IXUSR) != 0) ? 'x' : '-';
	tab[3] = ((mode & S_IRGRP) != 0) ? 'r' : '-';
	tab[4] = ((mode & S_IWGRP) != 0) ? 'w' : '-';
	tab[5] = ((mode & S_IXGRP) != 0) ? 'x' : '-';
	tab[6] = ((mode & S_IROTH) != 0) ? 'r' : '-';
	tab[7] = ((mode & S_IWOTH) != 0) ? 'w' : '-';
	tab[8] = ((mode & S_IXOTH) != 0) ? 'x' : '-';
	tab[9] = '\0';
	if (mode & S_ISUID)
		tab[2] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		tab[5] = (mode & S_IXGRP ? 's' : 'S');
	if (mode & S_ISVTX)
		tab[8] = (mode & S_IXOTH ? 't' : 'T');
	ft_putstr(tab);
}

int			print_type(t_lst *elem, char *flag)
{
	struct stat		s;
	int				error;

	if (lstat(elem->d_name, &s) != 0)
		return (errno);
	if (S_ISREG(s.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(s.st_mode))
		ft_putchar('d');
	else if (S_ISBLK(s.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(s.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(s.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(s.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(s.st_mode))
		ft_putchar('s');
	else
		ft_putchar('?');
	print_right(s.st_mode);
	if ((error = print_ui(elem, flag)) != 0)
		return (error);
	return (0);
}
