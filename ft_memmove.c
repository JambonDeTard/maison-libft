/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:38:25 by avillard          #+#    #+#             */
/*   Updated: 2022/11/08 10:39:10 by avillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*udst;
	unsigned char	*usrc;

	i = -1;
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (usrc < udst)
		while (len-- > 0)
			udst[len] = usrc[len];
	else
		while (++i < len)
			udst[i] = usrc[i];
	return (udst);
}
