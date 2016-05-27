/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:25:15 by alallema          #+#    #+#             */
/*   Updated: 2016/05/18 18:54:35 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_freelst(t_lst *lst)
{
	t_lst	*elem;
	t_lst	*tmp;

	elem = lst;
	while (elem)
	{
		tmp = elem->next;
		ft_memdel((void *)&elem->stat);
		ft_strdel(&elem->d_name);
		free(elem);
		elem = tmp;
	}
}
