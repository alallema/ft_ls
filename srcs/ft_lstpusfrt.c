/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpusfrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 15:27:09 by alallema          #+#    #+#             */
/*   Updated: 2016/05/20 17:56:47 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		ft_lstpusfrt(t_lst ***begin, char *d_name, char *flag)
{
	t_lst	*new;

	new = ft_lstcrea(d_name, flag);
	if (**begin)
		new->next = **begin;
	**begin = new;
}
