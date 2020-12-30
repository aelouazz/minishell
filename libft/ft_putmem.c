/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:30:11 by aelouazz          #+#    #+#             */
/*   Updated: 2020/10/31 01:36:13 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void *mem, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		ft_putchar((*(unsigned char *)mem) + i);
}
