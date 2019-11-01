/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:09:47 by thalfemp          #+#    #+#             */
/*   Updated: 2019/10/29 12:39:27 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (!(str = (void*)malloc(sizeof(*str) * size)))
		return (NULL);
	while (i < size)
	{
		((unsigned char*)str)[i] = '\0';
		i++;
	}
	return (str);
}
