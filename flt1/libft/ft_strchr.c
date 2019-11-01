/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:12:29 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/10 16:40:57 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;
	char	*s1;
	int		i;

	c1 = (char)c;
	s1 = (char*)s;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	if (c1 == '\0')
		return (&s1[i]);
	return (NULL);
}
