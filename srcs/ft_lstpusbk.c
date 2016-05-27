/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:11:44 by alallema          #+#    #+#             */
/*   Updated: 2016/05/20 18:51:55 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_lstpusbk(t_lst **elem, char *d_name, char *flag)
{
	t_lst	*new;
	t_lst	*tmp;

	tmp = *elem;
	if (elem != NULL)
	{
		new = ft_lstcrea(d_name, flag);
		new->next = tmp->next;
		tmp->next = new;
	}
	else
		tmp->next = ft_lstcrea(d_name, flag);
}
