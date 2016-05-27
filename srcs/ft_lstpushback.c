/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:11:44 by alallema          #+#    #+#             */
/*   Updated: 2016/05/18 18:01:21 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_lstpushback(t_lst **begin, char *d_name, char *flag)
{
	t_lst	*elem;

	elem = *begin;
	if (elem != NULL)
	{
		while (elem->next)
			elem = elem->next;
	}
	elem->next = ft_lstcrea(d_name, flag);
}
