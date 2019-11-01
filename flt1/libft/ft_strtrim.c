/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:34:42 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/12 13:21:44 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int			len_w_s(char const *s)
{
	int f_len;
	int len_1;
	int i;
	int count;

	f_len = len(s) - 1;
	len_1 = len(s);
	i = 0;
	count = 0;
	while (s[i] == ' ' || s[i] == '\n'
			|| s[i] == '\t')
		i++;
	if (i == len_1)
		return (0);
	while (s[f_len] == ' ' || s[f_len] == '\n'
			|| s[f_len] == '\t')
		f_len--;
	len_1 = len_1 - (len_1 - f_len) - i + 1;
	return (len_1);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s == 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * (len_w_s(s) + 1))))
		return (NULL);
	i = 0;
	j = len(s) - 1;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n'
			|| s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n'
			|| s[j] == '\t')
		j--;
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
