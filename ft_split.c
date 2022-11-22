/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:11:28 by avillard          #+#    #+#             */
/*   Updated: 2022/11/22 11:44:29 by avillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_c_is_in_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	else
		return (0);
}

int	ft_count(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_c_is_in_charset(str[i], charset) && str[i])
			i++;
		if (!(ft_c_is_in_charset(str[i], charset)) && str[i])
		{
			count++;
			while (!(ft_c_is_in_charset(str[i], charset)) && str[i])
				i++;
		}
	}
	return (count);
}

char	*ft_strcpy(char const *src, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (dest);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen_split(char const *str, char charset)
{
	int	len;

	len = 0;
	while (str[len] && !(ft_c_is_in_charset(str[len], charset)))
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		lencpy;
	int		lentab;

	i = 0;
	j = 0;
	lentab = ft_count(s, c);
	tab = malloc(sizeof(char const *) * (lentab + 1));
	if (!tab)
		return (NULL);
	while (j < lentab)
	{
		while (ft_c_is_in_charset(s[i], c))
			i++;
		lencpy = ft_strlen_split(&s[i], c);
		tab[j] = ft_strcpy(&s[i], lencpy);
		j++;
		i += lencpy;
	}
	tab[j] = NULL;
	return (tab);
}
