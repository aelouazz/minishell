/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:31:31 by aelouazz          #+#    #+#             */
/*   Updated: 2020/10/31 01:34:28 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnclear(t_list **begin_list, int nb)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = *begin_list;
	tmp = NULL;
	i = -1;
	while (list && ++i < nb)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		free(list);
		list = tmp;
	}
	*begin_list = NULL;
	return (list);
}
