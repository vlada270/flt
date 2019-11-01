/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:48:08 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/12 09:04:11 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 0;
	j = 0;
	s1 = (char*)haystack;
	s2 = (char*)needle;
	if (*s2 == 0)
		return (s1);
	while (s1[j] != '\0')
	{
		if (s1[j] == s2[0])
		{
			i = 0;
			while (s1[j + i] == s2[i] && s2[i])
				i++;
			if (s2[i] == '\0')
				return (s1 + j);
		}
		j++;
	}
	return (NULL);
}
