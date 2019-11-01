/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:30:17 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/16 15:19:01 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(const char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != '\0')
			count++;
		while (*str != c && *str != '\0')
			str++;
	}
	return (count);
}

static int		len_w(const char *str, char c)
{
	int i;

	i = 0;
	while (*str != c && *str)
	{
		str++;
		i++;
	}
	return (i);
}

static int		create_massive(char const *str, char **tab, int i, int len)
{
	int x;

	x = 0;
	if (!(tab[i] = (char*)malloc(sizeof(*str) * (len + 1))))
		return (0);
	while (x < len)
	{
		tab[i][x] = str[x];
		x++;
	}
	tab[i][x] = '\0';
	return (1);
}

char			**ft_strsplit(char const *str, char c)
{
	int		k;
	int		len;
	int		i;
	char	**tab;

	i = -1;
	if (str == 0)
		return (NULL);
	k = words(str, c);
	tab = (char**)malloc(sizeof(char*) * (k + 1));
	if (tab == 0)
		return (NULL);
	while (i++ < k - 1)
	{
		while (*str == c)
			str++;
		len = len_w(str, c);
		if (create_massive(str, tab, i, len) == 0)
			return (0);
		while (*str != c && *str != '\0')
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
