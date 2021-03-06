/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:56:24 by aelouazz          #+#    #+#             */
/*   Updated: 2019/04/26 19:56:41 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** Append the @s2 to the end of the @s1 (including the Null char of the @s2)   |
** -----------------------------------------------------------------------------
*/

char				*ft_strcat(char *s1, const char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	str = s1;
	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = s2[j];
	return (s1);
}
