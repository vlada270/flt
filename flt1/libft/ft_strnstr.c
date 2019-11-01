/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:53:01 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/12 13:35:08 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*s1;
	char		*s2;

	i = 0;
	j = 0;
	s1 = (char*)haystack;
	s2 = (char*)needle;
	if (*s2 == 0)
		return (s1);
	while (s1[j] != '\0' && j != len)
	{
		if (s1[j] == s2[0])
		{
			i = 0;
			while (s1[j + i] == s2[i] && s2[i] && j + i < len)
				i++;
			if (s2[i] == '\0')
				return (s1 + j);
		}
		j++;
	}
	return (NULL);
}
