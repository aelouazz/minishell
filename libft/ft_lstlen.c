/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:45:13 by aelouazz          #+#    #+#             */
/*   Updated: 2020/10/31 01:33:39 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *blist)
{
	int		i;
	t_list	*list;

	i = 0;
	if (blist)
	{
		list = blist;
		while (list)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}
