/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:50:37 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/12 10:25:41 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*s11;
	char	*s12;

	i = 0;
	s11 = (char*)s1;
	s12 = (char*)s2;
	while (s11[i] == s12[i] && s11[i] != '\0' && s12[i] != '\0'
			&& i < n)
		i++;
	if (s11[i] == '\0' && s12[i] == '\200')
		return (-128);
	if (s11[i] == '\200' && s12[i] == '\0')
		return (128);
	if (i == n)
		return (0);
	return ((unsigned char)s11[i] - (unsigned char)s12[i]);
}
