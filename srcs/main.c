/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:24:46 by alallema          #+#    #+#             */
/*   Updated: 2016/05/26 15:50:46 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void	check_opt(char c, char *flag)
{
	if (c == 'n' || c == 'o' || c == 'g')
	{
		flag[0] = '1';
		if (c == 'n')
			flag[5] = '1';
		if (c == 'o')
			flag[6] = '1';
		if (c == 'g')
			flag[7] = '1';
	}
}

static void	check_flag(char *s, char *flag)
{
	if (s[0] == '-')
	{
		s++;
		while (*s && (*s == 'l' || *s == 'R' || *s == 'r' || *s == 'a' ||
				*s == 't' || *s == 'n' || *s == 'o' || *s == 'g'))
		{
			if (*s == 'l')
				flag[0] = '1';
			if (*s == 'R')
				flag[1] = '1';
			if (*s == 'r')
				flag[2] = '1';
			if (*s == 'a')
				flag[3] = '1';
			if (*s == 't')
				flag[4] = '1';
			check_opt(*s, flag);
			s++;
		}
	}
}

static int	check_arg(char *s2, char *flag)
{
	char	*s;

	s = s2;
	if (s[0] != '-' || (s[0] == '-' && !s[1]))
		return (1);
	if (s[0] == '-' && s[1] == '-' && !s[2])
		return (0);
	if (s[0] == '-')
	{
		s++;
		while (*s == 'l' || *s == 'R' || *s == 'r' || *s == 'a' || *s == 't'
			|| *s == 'n' || *s == 'o' || *s == 'g')
			s++;
		if (*s)
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(*s);
			ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
			exit(0);
		}
	}
	if (flag[0] != '\0')
		check_flag(s2, flag);
	return (0);
}

void		ft_make_lst_arg(char **arg, char *flag, int nb)
{
	int		j;
	t_lst	*lst;

	j = 0;
	while (arg[j])
	{
		if (j != 0 && opendir(arg[j]))
			ft_putchar('\n');
		if (nb > 1 && opendir(arg[j]))
		{
			ft_putstr(arg[j]);
			ft_putstr(":\n");
		}
		lst = ft_ls(arg[j++], flag);
	}
	if (j == 0)
		ft_ls(".", flag);
}

int			main(int ac, char **av)
{
	int		i;
	int		j;
	char	*flag;
	char	*arg[ac];

	flag = ft_strdup("00000000");
	i = 1;
	j = 0;
	while (ac > i && check_arg(av[i], flag) == 0)
		i++;
	while (ac > i)
	{
		if (check_arg(av[i], flag) < 0)
			return (0);
		else if (check_arg(av[i], "") == 0)
			i++;
		else
			arg[j++] = ft_strdup(av[i++]);
	}
	arg[j] = NULL;
	ft_make_lst_arg(arg, flag, j);
	free(flag);
	return (0);
}
