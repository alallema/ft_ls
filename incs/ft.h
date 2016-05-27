/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:09:48 by alallema          #+#    #+#             */
/*   Updated: 2016/05/26 15:36:56 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# define L (flag[0])
# define R (flag[1])
# define RM (flag[2])
# define A (flag[3])
# define T (flag[4])
# define N (flag[5])
# define O (flag[6])
# define G (flag[7])
# define T_SEC (elem->stat->st_mtimespec.tv_sec)
# define T_NSEC (elem->stat->st_mtimespec.tv_nsec)
# define T_SECN (elem->next->stat->st_mtimespec.tv_sec)
# define T_NSECN (elem->next->stat->st_mtimespec.tv_nsec)
# define TV_SEC (s.st_mtimespec.tv_sec)
# define TV_NSEC (s.st_mtimespec.tv_nsec)
# define LSTAT (lstat(o_dir, &s) != 0)

typedef struct timespec	t_time;

typedef struct stat		t_stat;

typedef struct			s_lst
{
	t_stat				*stat;
	char				*d_name;
	struct s_lst		*next;
}						t_lst;

char					*ft_clean_name(char *s, int err);
int						ft_print_err(char *o_dir);
void					ft_lstpusfrt(t_lst ***lst, char *d_name, char *flag);
void					ft_sortlst(t_lst **lst, char *d_name, char *flag);
void					ft_sortrev(t_lst **lst, char *d_name, char *flag);
char					*ft_str_odir(char *o_dir, char *d_name);
t_lst					*ft_lstcrea(char *d_name, char *flag);
void					ft_lstpusbk(t_lst **begin, char *d_name, char *flag);
t_lst					*ft_ls(char *o_dir, char *flag);
int						print_type(t_lst *elem, char *flag);
void					print_lst(t_lst *lst, char *flag, int err);
void					ft_freelst(t_lst *lst);

#endif
