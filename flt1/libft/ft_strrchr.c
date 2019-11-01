/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:20:44 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/11 17:38:55 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	char	*s1;
	char	*temp;
	int		i;
	int		k;

	c1 = (char)c;
	s1 = (char*)s;
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c1)
		{
			k = 1;
			temp = &s1[i];
		}
		i++;
	}
	if (c1 == s1[i])
		return (&s1[i]);
	if (k == 0)
		return (NULL);
	return (temp);
}
